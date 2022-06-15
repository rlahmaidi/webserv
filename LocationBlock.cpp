#include "LocationBlock.hpp"

LocationBlock& LocationBlock::operator=(const LocationBlock& instance) {
	std::cout << "Copy LocationBlock assignement operator" << std::endl;
	this->max_body_size = instance.max_body_size;
	this->Error_page = instance.Error_page;
	this->root = instance.root;
	return *this;
}

LocationBlock::LocationBlock(const LocationBlock& instance) {
	std::cout << "Copy LocationBlock Constructor" << std::endl;
	*this = instance;
}

LocationBlock::LocationBlock() {
	std::cout << "LocationBlock Constructor" << std::endl;
}

LocationBlock::~LocationBlock() {
	std::cout << "LocationBlock Destructor" << std::endl;
}
