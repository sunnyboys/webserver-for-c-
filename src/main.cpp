#include<iostream>
#include "../head/request.h"
#include "../head/serverSocket.h"

int main(){
	ServerSocket *ss = new ServerSocket(8000);
	ss->socketBind();
	ss->socketListen();
	while(true){
		std::cout<<"===========accept======"<<std::endl;
		int connect_fd = ss->socketAccept();
		ss->recvProto(connect_fd);
		//std::cout<<"recv content:"<< *content<<std::endl;
		//char str[6] = "nihao\n";
		ss->sendProto(connect_fd);
		ss->closeConnected(connect_fd);
	}
	ss->closeSocket();
	delete(ss);
	return 0;
}
