//#include "server.h"
#include "network.h"

std::string getTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S --- ",localtime(&timep));
    return tmp;
}

Network* network = NULL;
/*****************************************************************************************/

Network::Network():
	Epoolfd(0),
	Listenfd(0),
	Thread(nullptr),
	Frame(0){
	PacketMap.clear();
}

Network* Network::Instance(){
	if(network == NULL){
		network = new Network();
	}
	return network;
}

Network::~Network(){
	if(nullptr != Thread){
		Thread->join();
	}
	delete Thread;
	close(Listenfd);

	PacketMap.clear();
	std::cout << "close network!"<<std::endl;
}

bool Network::init(){
	Epoolfd = epoll_create(MAXEVENTSIZE);
	return true;	
}

bool Network::createServer(const char* ip, int port){
	unsigned long m_addr = INADDR_ANY;

	Listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(Listenfd == -1){
		std::cout << "create socket failed"<<std::endl;
	}

	if (ip[0] != '\0')
    {
        m_addr = inet_addr(ip);
        if (m_addr == INADDR_NONE)
            m_addr = INADDR_ANY;
    }

    int flag = 1;  
    if (-1 == setsockopt(Listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag))) {  
        std::cout<< "setsockeopt failed "<< std::endl;
    }  

    int		keepIdle = 600;
	int 	keepInterval = 10;
	int 	keepCount = 10;
	setsockopt(Listenfd, SOL_TCP, TCP_KEEPIDLE, (void *)&keepIdle, sizeof(keepIdle));
	setsockopt(Listenfd, SOL_TCP,TCP_KEEPINTVL, (void *)&keepInterval, sizeof(keepInterval));
	setsockopt(Listenfd, SOL_TCP, TCP_KEEPCNT, (void *)&keepCount, sizeof(keepCount));


	struct sockaddr_in server_addr;
	memset(&server_addr, 0 , sizeof(sockaddr_in));  //set zero
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = m_addr;
	server_addr.sin_port = htons(port);

	if(-1 == bind(Listenfd, (struct sockaddr*)(&server_addr), sizeof(server_addr))){
		std::cout << " bind socket failed"<<std::endl;
		return false;
	}

	if(-1 == listen(Listenfd, 8)){
		std::cout << " listen socket failed"<<std::endl;
		return false;
	}

	ctlEvent(Listenfd, true, _Server);
	std::cout << "CreateListenPort:"<<ip<<":"<<port<<" Success!"<<std::endl;

	return true;
}

int Network::connectServer(const char* ip, int port){
	int socketfd;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1){
        std::cout << "new socket failed!\n" << std::endl;
        return -1;
    }

    struct sockaddr_in sa;
    bzero(&sa, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = inet_addr(ip);
    bzero(&(sa.sin_zero), 8);

    if(-1 == connect(socketfd, (struct sockaddr *)&sa, sizeof(sa))){
        printf("connect failed!\n");
        return -1;
    }
    ctlEvent(socketfd,true,_Server);
    return socketfd;
}

void Network::ctlEvent(int fd, bool flag, PacketType type){
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = flag ? EPOLLIN : 0;
	epoll_ctl(Epoolfd, flag ? EPOLL_CTL_ADD : EPOLL_CTL_DEL, fd, &ev);
	if(flag){
		setNoblock(fd);

		Packet* packet = new Packet(fd);
		packet->setType(type);
		PacketMap[fd] = packet;
		
		if(fd != Listenfd){
			std::cout <<"fd:"<< fd << " add to loop." << std::endl;			
		}
	}
	else{
		close(fd);
		LuaMgr* luaMgr = LuaMgr::Instance();
		luaMgr->disConnect(PacketMap[fd]);
		PacketMap.erase(fd);
		std::cout <<"fd:"<< fd << " exit from loop." << std::endl;
	}
}

int Network::epollLoop(){
	using namespace std::chrono;

	struct sockaddr_in client_addr;
	socklen_t client_len;
	int nfds = 0;
	int fd = 0;
	int bufflen = 0;
	struct epoll_event events[MAXEVENTSIZE];
	while(true){
    	steady_clock::time_point tpBegin = steady_clock::now();
		nfds = epoll_wait(Epoolfd, events, MAXEVENTSIZE, TIMEWAIT);
		for(int i = 0; i < nfds; i++){
			std::cout <<getTime()<< "get msg event form fd:" << events[i].data.fd<< std::endl;
			if(events[i].data.fd == Listenfd){
				fd = accept(Listenfd, (struct sockaddr*)&client_addr, &client_len);
				ctlEvent(fd, true, _Client);
				char ipAddress[INET_ADDRSTRLEN];
				std::cout << "accept connection from :"<<inet_ntop(AF_INET, &client_addr.sin_addr, ipAddress, sizeof(ipAddress))<<":"<<ntohs(client_addr.sin_port)<< std::endl;

				newConnect(fd);
			}
			else if(events[i].events & EPOLLIN){
				if((fd == events[i].data.fd) < 0) 
					continue;
				processTcpPackage(events[i].data.fd);
			}
		}
		milliseconds dur;
        do{
			steady_clock::time_point tpNow = steady_clock::now();
	        dur = duration_cast<milliseconds>(tpNow - tpBegin);
            std::this_thread::sleep_for(milliseconds(10));
        }while (dur.count() * FPS < 1000);

        // Frame++;
	}
}

int Network::setNoblock(int fd){
	int flags;
	if((flags == fcntl(fd, F_GETFL, 0)) == -1) 
		flags = 0;
	return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void Network::run(){
	std::cout << "network is runing!" <<std::endl;
	Thread = new std::thread(&Network::epollLoop, this);
	//Thread->detach();

	// new std::thread(&Network::breathe,this);
	//Thread->detach();
}

void Network::processTcpPackage(int fd){
	std::cout << "get data from:" << fd << std::endl;
	Packet *packet = PacketMap[fd];
	switch(packet->addPacket(fd)){
		case -1:
			ctlEvent(fd,false,_Client);
			break;
		case 1:
			processBreathe(packet);
			// Msg msg ;
			// msg = packet->recvMsg();
			// if(msg.cmd == breathe_cmd)
			// 	processBreathe(msg);
			// else
			// 	msgMgr.addMsg(&msg);
			break;
		case 0:
			std::cout << "wait a new packet" << std::endl;	
			break;
	}
}

void Network::processBreathe(Packet * packet){
	LuaMgr* luaMgr = LuaMgr::Instance();
	if(packet->getCmd() == breathe_cmd){
		packet->breatheGet();
	}else{
		luaMgr->recvData(packet);
	}
}

void Network::breathe(int fps){
	// while(true) {
		// using namespace std::chrono;
  //   	steady_clock::time_point tpBegin = steady_clock::now();
		for(auto it = PacketMap.begin();it!=PacketMap.end();it++){
			Packet* packet = it->second;
			// std::cout << "breathe fd:" << connect.fd <<"count:"<<connect.count<< std::endl;
			if(packet->needClose(fps)){
				std::cout << "close fd:" << packet->getFd()<< std::endl;
				ctlEvent(packet->getFd(),false,_Client);
			}else{
				packet->breathe();
			}
		}

		// milliseconds dur;
  //       do{
		// 	steady_clock::time_point tpNow = steady_clock::now();
	 //        dur = duration_cast<milliseconds>(tpNow - tpBegin);
		// 	std::this_thread::sleep_for(milliseconds(1000));
  //       }while(dur.count()< 10000);
	// }
}

void Network::newConnect(int fd){
	// Msg * msg = new Msg;
	// msg->fd = fd;
	// msg->cmd = fd_newconnect;
	// memset(msg->buff,0,(size_t)2048);
	// msgMgr.addMsg(msg); 
	LuaMgr* luaMgr = LuaMgr::Instance();
	luaMgr->newConnect(PacketMap[fd]);
}

Packet* Network::getPacket(int fd){
	return PacketMap[fd];
}

Packet* Network::getListen(){
	return PacketMap[Listenfd];
}