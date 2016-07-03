#include"../head/response.h"
#include<iostream>
#include <sys/stat.h>

#define BUFFER_SIZE 2048

void Response::sendProto(ServerSocket* ss, int connect_fd, const std::string uri)
{
	std::string fname = "webroot" + uri;
	char buffer[BUFFER_SIZE];
	FILE *fp = fopen(fname.c_str(),"r");
	int fsize = 0;
	if(fp == NULL){
		std::cout<<"file open error fileName:"<<fname.c_str()<<std::endl;
		sendHeader(ss, connect_fd, 404, fsize);
	}else{
		struct stat st;
		stat(fname.c_str(), &st);
		fsize = st.st_size;
		printf("+++++++++fileSize:%d\n", fsize);
		sendHeader(ss, connect_fd, 200, fsize);
		bzero(buffer, BUFFER_SIZE);
		int fileBlockLen = 0;
		while((fileBlockLen = fread(buffer, sizeof(char), BUFFER_SIZE, fp))		> 0){
			printf("file_block_length = %d\n", fileBlockLen);
			ss->sendProto(connect_fd, buffer, fileBlockLen);
	}
	fclose(fp);
	fp = NULL;

}
}

void Response::sendHeader(ServerSocket* ss, int connect_fd, int code, int fsize)
{
	std::string headStr = "HTTP/1.1 ";
	switch(code){
		case 200:
			headStr += "200 OK";
			break;
		case 404:
			headStr += "404 error";
			break;
	}
	headStr += "\nContent-Type:text/html\nContent-Length:";
	char fsizeStr[10];
	sprintf(fsizeStr, "%d", fsize);
	headStr += fsizeStr;
	headStr += "\n\n";
	char buffer[BUFFER_SIZE];
	strncpy(buffer, headStr.c_str(), sizeof(buffer));
	ss->sendProto(connect_fd,buffer, sizeof(buffer));
	//std::cout<<"-----send head:"<<headStr<<std::endl;
}
