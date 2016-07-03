#ifndef REQUEST_H
#define REQUEST_H
#include<iostream>
class Request
{
	private:
		std::string _requestStr;
		std::string _requestType;
		std::string _uri;
		std::string _url;
		void parse();
	public:
		void setRequestStr(const std::string str);
		const std::string getUri();
		const std::string getUrl();

};

#endif
