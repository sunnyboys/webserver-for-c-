#include<iostream>
#include "../head/request.h"
#include "../head/serverSocket.h"
#include "../head/response.h"

int main(){
	ServerSocket *ss = new ServerSocket(8000);
	ss->socketBind();
	ss->socketListen();
	while(true){
		std::cout<<"===========accept======"<<std::endl;
		int connect_fd = ss->socketAccept();
		std::string str = ss->recvProto(connect_fd);
		std::cout<<"main recv str:"<< str <<std::endl;
		Request r;
		r.setRequestStr(str);
		//ss->sendProto(connect_fd);
		Response res;
		res.sendProto(ss, connect_fd, r.getUri());
		std::cout<<"======send end======="<<std::endl;
		ss->closeConnected(connect_fd);
		std::cout<<"=======close connected"<<std::endl;
	}
	ss->closeSocket();
	delete(ss);
	return 0;
}
