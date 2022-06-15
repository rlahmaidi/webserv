# ifndef TOOLS_CPP_HPP
#define TOOLS_CPP_HPP

#include "ServerBlock.hpp"
#include "LocationBlock.hpp"
#include "tools.hpp"

void	parsingConfigFile(char *argv, std::vector<ServerBlock>& servers);
void	parser(std::ifstream& config_file, std::vector<ServerBlock>& servers);
std::vector<std::string> split_line_to_tokens(std::string line);
std::vector<std::string> split_token_with_del(std::string line, int del);

int checkForAcoladeServ(std::vector<std::string>& tokens, size_t len);
int checkForAcoladeLocation(std::vector<std::string>& tokens, LocationBlock& newServer);
int     fill_server(std::vector<std::string> tokens,ServerBlock& newServer);
int    fill_location(std::vector<std::string>loc, LocationBlock& newLocation);
int find_del(std::string str, int del);
#endif