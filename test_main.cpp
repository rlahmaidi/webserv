#include <iostream>
#include <vector>

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

#include <string>
int main()
{
    // std::vector<std::string> vec(2,"ra");
    // std::vector<std::string>::iterator iter;
    // std::string  str = "chih aja";

    // for(iter = vec.begin(); iter != vec.end(); ++iter)  
    //     std::cout << *iter << std::endl;
    // vec = split_line_to_tokens(str);
    // for(iter = vec.begin(); iter != vec.end(); ++iter)  
    //     std::cout << *iter << std::endl;

	std::cout << sizeof(1) << std::endl;
}