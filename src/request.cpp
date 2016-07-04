#include "../head/request.h"

void Request::setRequestStr(const std::string str){
	this->_requestStr = str;
	parse();
}

void Request::parse()
{
	int idx1 = _requestStr.find_first_of(" ");
	this->_requestType = _requestStr.substr(0, idx1);
	std::cout<<"request type:"<<_requestType<<"+pos:"<<idx1<<std::endl;
	int idx2 = _requestStr.find_first_of(" ", idx1 + 1);
	_uri = _requestStr.substr(idx1+1, idx2 - idx1 - 1);
	std::cout<<"uri:"<<_uri<<" +pos:"<<idx2<<std::endl;

}

const std::string Request::getUri()
{
	return _uri;
}

std::string Request::getName()
{
	return name;
}
