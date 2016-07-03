#ifndef RESPONSE_H
#define RESPONSE_H
#include"../head/serverSocket.h"
class Response
{
	private:
		void sendHeader(ServerSocket* ss, int connect_fd, int code, int fsize);

	public:
		void sendProto(ServerSocket* ss, int connect_fd, const std::string uri);
};
#endif
