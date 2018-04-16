#include "packet.h"

Packet::Packet(int _fd){
	fd = _fd;
	cmd = 0;
	offset = 0;
	length = MAXLEN;
	bzero(buff,strlen(buff));
	bzero(cache,strlen(buff));
	type = Server;
	breathe_count = 0;
	nRef = -2;
	//type = 0;
}

Packet::~Packet(){

}

int Packet::addPacket(int fd){
	int readlen = read(fd, cache+offset, MAXLEN-offset);
	offset += readlen;
	if(offset <= 0){
		return -1;
	}

	if(offset >= 2){
		// length = cache[0]+(cache[1]<<8);
		memcpy(&length,cache,2);
		std::cout << "bufflen :" << length <<"--"<<cache[0]+(cache[1]<<8)<<std::endl;
		std::cout << "length:" << length << "++" <<std::bitset<16>(length)<< std::endl;
		//std::cout << "length:" << (unsigned short)cache[0] << "++" <<std::bitset<16>(cache[0])<< std::endl;
		//std::cout << "length:" << (cache[1]<<8) << "++" <<std::bitset<16>((cache[1]<<8))<< std::endl;
		// length = cache[0]+(cache[1]<<8);
	}
	
	if(offset >= length){ //get all request data
		cmd =cache[2]+(cache[3]<<8);
		std::cout << "cmd:" << cmd << std::endl;
		memcpy(buff,cache+4,length-4);
		// std::cout <<"bufflen:"<< strlen(buff)<<std::endl;
		std::cout <<"bufflen:"<< strlen(buff)<<std::endl;
		// std::cout <<"buff:"<< buff<<std::endl;

		//add packet to client

		offset -= length;
		if(offset > 0){
			memcpy(cache,cache+length,offset);
		}
		length = MAXLEN;
		return 1;
	}
	return 0;
}

// Msg Packet::recvMsg(){
// 	Msg msg;
// 	msg.fd = getFd();
// 	msg.cmd = getCmd();
// 	memcpy(msg.buff,getBuff(),strlen(getBuff()));
// 	bzero(getBuff(),strlen(getBuff()));
// 	return msg;
// }

void Packet::sendData(short len, short cmd,const char * data){
	len += 4;
	char * datatoh = new char[len];

	bzero(datatoh,strlen(datatoh));
	memcpy(datatoh,&len,2);
	memcpy(datatoh+2,&cmd,2);
	memcpy(datatoh+4,data,len-4);
	int sendlen = 0;
	while(sendlen < len) {
		sendlen += write(fd,datatoh+sendlen,len-sendlen);
	}
}

// void Packet::sendMsg(int fd,const Msg* msg){
// 	short len = strlen(msg->buff)+4;
// 	char * datatoh = new char[len];

// 	std::cout << "send length:" << len<< "	fd:"<<fd<<std::endl;
//     std::cout << "length:" << len << "++" <<std::bitset<16>(len)<< std::endl;
//     bzero(datatoh,strlen(datatoh));
// 	memcpy(datatoh,&len,2);
// 	memcpy(datatoh+2,&(msg->cmd),2);
// 	memcpy(datatoh+4,msg->buff,len-4);

// 	std::cout << "send length:" << len<< " fd:"<<fd<<std::endl;
// 	int sendlen = 0;
// 	while(sendlen < len){
// 		sendlen += write(fd, datatoh+sendlen, len-sendlen);
// 	}
// }

short Packet::getLength(){
	return length;
}

char* Packet::getBuff(){
	return buff;
}

int Packet::getFd(){
	return fd;
}

short Packet::getCmd(){
	return cmd;
}

bool Packet::needClose(){
	return breathe_count > time_out;
}

void Packet::breatheGet(){
	breathe_count = 0;
}

void Packet::breathe(){
	if(type == Client)
		breathe_count += 1;
}

void Packet::setType(PacketType type){
	this->type = type; 
}

void Packet::setRef(int nRef){
	this->nRef = nRef;
}

int Packet::getRef(){
	return nRef;
}