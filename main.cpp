#include "tools_cpp.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		try {
				std::vector<ServerBlock> servers;
				parsingConfigFile(argv[1], servers);
	
				// printConfigFile(servers);	// Printing Server Block
				std::vector<ServerBlock>::iterator iter;
				for (iter = servers.begin(); iter != servers.end(); ++iter)
				{
					std::cout << "Host: "<< iter->host << std::endl;
					std::cout << "Port: "<< iter->port << std::endl;
					std::cout << "Root: " << iter->root << std::endl;
					std::cout << "max_body_size: " << iter->max_body_size << std::endl;
					//std::cout << "index: " << iter->index << std::endl;

					std::cout << "-----------------------------" << std::endl;
				}
		}
		catch (...) {
			std::cout << "" << std::endl;
		}
	}
	else
		std::cout << "Bad number of args" << std::endl;
	return (0);
}
