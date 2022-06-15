#include "tools_cpp.hpp"

// Ressource: https://github.com/emy-sg/CPP__/blob/master/day_01/ex04/main.cpp

// Method of std::istream::getline : https://m.cplusplus.com/reference/istream/istream/getline/

void	parser(std::ifstream& config_file, std::vector<ServerBlock*>& servers)
{
		if (servers.size())
		std::cout << "full" << std::endl;
	//std::string line;

	// 1- getline and store it in string  // expect "server" then "{"
	//while (getline(config_file, line))
	//{
		// 2- check if server block
		//if (line.substr(0, 6) == "server")
		//{
		//	servers(parseServerBlock(config_file));
		//}
	//}

	// 2- 






	config_file.close();
	//servers.push_back(ServerBlock());
	//servers.push_back(ServerBlock());
	//servers.push_back(ServerBlock());
	//servers.push_back(ServerBlock());
}
