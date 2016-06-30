#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_BUFF 4096

class ServerSocket
{
	private:
		int _socket_fd;
		struct sockaddr_in _servaddr;

	public:
		ServerSocket(int port);
		void socketBind();
		void socketListen();
		int socketAccept();
		void recvProto(int connect_fd);
		void sendProto(int connect_fd);
		void closeConnected(int connect_fd);
		void closeSocket();
		
};

#endif
