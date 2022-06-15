#include "ServerBlock.hpp"

ServerBlock& ServerBlock::operator=(const ServerBlock& instance) {
	std::cout << "Copy ServerBlock assignement operator" << std::endl;
	this->host = instance.host;
	this->port = instance.port;
	this->server_names = instance.server_names;
	this->max_body_size = instance.max_body_size;
	this->Error_page = instance.Error_page;
	this->root = instance.root;
	return *this;
}

ServerBlock::ServerBlock(const ServerBlock& instance) {
	std::cout << "Copy ServerBlock Constructor" << std::endl;
	*this = instance;
}

ServerBlock::ServerBlock() {
	std::cout << "ServerBlock Constructor" << std::endl;
	port = -1;
	max_body_size = -1;
	//**** RACHID ADDED THIS***** 
	host = "";
}

ServerBlock::~ServerBlock() {
	std::cout << "ServerBlock Destructor" << std::endl;
}

