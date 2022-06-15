# ifndef LOCATIONBLOCK_HPP
#define LOCATIONBLOCK_HPP


#include "tools.hpp"


class LocationBlock {
	public:
		long long int max_body_size;	  // int
		std::string Error_page; // string
		std::string root;      // string
		//I ADDED THIS
		std::string path;

		// Canonical form
		LocationBlock();
		~LocationBlock();
		LocationBlock(const LocationBlock& instance);
		LocationBlock& operator=(const LocationBlock& instance);
};

#endif