#include "tools_cpp.hpp"

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

