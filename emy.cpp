#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split_line_to_tokens(std::string line)
{
	std::vector<std::string> tokens;

	int i;
	int	j;
	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ' ')
		{
			i++;
			j = 0;
		}
		else
		{
			while (line[i + j] && line[i + j] != '\t' && line[i + j] != ' ')
				j++;
			if (j != 0)
			{
				tokens.push_back(line.substr(i, j));
				i += j;
			}
		}
	}
	return (tokens);
}

std::vector<std::string> split_token_with_del(std::string line, int del)
{
	std::vector<std::string> tokens;

	int i;
	int	j;
	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == ' ' || line[i] == del)
		{
			i++;
			j = 0;
		}
		else
		{
			while (line[i + j] && line[i + j] != '\t' && line[i + j] != ' ' && line[i + j] != del)
				j++;
			if (j != 0)
			{
				tokens.push_back(line.substr(i, j));
				i += j;
			}
		}
	}
	return (tokens);
} 

int main()
{

	//std::string line = "server_name google emy rachid";

	std::string line = "listen 192.0.0.1:80";
	std::vector<std::string> tokens;

	tokens = split_line_to_tokens(line);

	// 0- delete "server_name"
	//std::cout << "Gonna erase: " << tokens.at(0) << std::endl;
	if (tokens.at(0) != "#" && tokens.at(0)[0] != '#')
	{
			tokens.erase(tokens.begin() + 0);
			// 1- iter over the vector
			std::cout << "Print tokens: " << std::endl;

			std::vector<std::string> dir;
			dir = split_token_with_del(tokens.at(0), ':');
			std::vector<std::string>::iterator iter;
			for (iter = dir.begin(); iter != dir.end(); iter++)
			{
				std::cout << *iter << std::endl;
			}
		
	}
	return (0);
}
 
// swich cases of server directive {};
// swich cases of location directive {};

// if ROOT does not exist in the server 
// if port or host does not exist, fill it with the default values "8080" "0.0.0.0" 
