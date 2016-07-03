#include "../head/serverSocket.h"

ServerSocket::ServerSocket(int port)
{
	if((_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("create socket error:%s(errno:%d)\n", strerror(errno), errno);
		exit(0);
	}

	memset(&_servaddr, 0, sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	_servaddr.sin_port = htons(port);
}

void ServerSocket::socketBind()
{
	if(bind(_socket_fd, (struct sockaddr*)&_servaddr, sizeof(_servaddr)) == -1){
		printf("bind socket error:%s(errno:%d)\n", strerror(errno), errno);
		exit(0);
	}
}

void ServerSocket::socketListen()
{
	if(listen(_socket_fd, 10) == -1){
		printf("listen socket error:%s(errno:%d)\n", strerror(errno), errno);
		exit(0);
	}
}

int ServerSocket::socketAccept()
{
	int connect_fd;
	if((connect_fd = accept(_socket_fd, (struct sockaddr*)NULL, NULL)) == -1){
		printf("accept socket error:%s(errno:%d)\n", strerror(errno), errno);
		return -1;
	}
	return connect_fd;
}

std::string ServerSocket::recvProto(int connect_fd)
{
	char buff[MAX_BUFF];
	int n = recv(connect_fd, buff, MAX_BUFF, 0);
	return buff;
}

void ServerSocket::sendProto(int connect_fd, char* buff, int len)
{
	if(send(connect_fd, buff, len, 0) == -1){
		perror("send error");
		close(connect_fd);
		exit(0);
	}
	printf("send=======content:%s", buff);
}

void ServerSocket::closeConnected(int connect_fd)
{
	close(connect_fd);
}

void ServerSocket::closeSocket()
{
	close(_socket_fd);
}
