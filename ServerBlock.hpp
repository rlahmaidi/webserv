# ifndef SERVERBLOCK_HPP
#define SERVERBLOCK_HPP

#include "LocationBlock.hpp"
#include "tools.hpp"


class ServerBlock {
	public:
		std::string host; // string
		int	port;	  // int
		std::vector<std::string> server_names; // string
		long long int max_body_size;	  // int
		std::string Error_page; // string
		std::string root;      // string
		//I ADDED THIS
		std::vector<LocationBlock> lacationBlock;
		std::vector<std::string>	index;
		std::string					autoindex;
		size_t						client_max_body_size;

		// Canonical form
		ServerBlock();
		~ServerBlock();
		ServerBlock(const ServerBlock& instance);
		ServerBlock& operator=(const ServerBlock& instance);
};

#endif