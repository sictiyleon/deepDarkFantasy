#ifndef __DBHANDLER__
#define __DBHANDLER__

#include "../baseServer/handler.h"
#include "../baseServer/Protos.pb.h"

class DbHandler:public Handler
{
public:
	DbHandler();
	virtual ~DbHandler();

  	virtual void handleMsg(Msg *msg);
  	static void sendDataToDb(int cmd,char *buff);
	static void selectRank();
	static void breatheToDb();

private:
	void getRank(Msg * msg);

};

#endif
