#include "tools_cpp.hpp"

int checkForAcoladeServ(std::vector<std::string>& tokens, size_t len) // I WILL CHANGE IT FOR {
{
	if (tokens.at(0).substr(0, len) == "server")			// "server" "{sdf" || "server{ghfs"
	{
		// Check for {
		if (tokens.at(0).length() == len)  // "server" "{dfgdfgdf"
		{
			if (tokens.at(1)[0] == '{')   
			{
				if (tokens.at(1).length() == 1)  // "server" "{"
				{
					tokens.erase(tokens.begin());
					tokens.erase(tokens.begin() + 1);
				}
				else	// "server" "{FDSDFS"
					tokens.at(1) = tokens.at(1).substr(1, tokens.at(1).length() - 1);
			}
			else
				return (1);
		}
		else if (tokens.at(0).length() >= (len + 1) && tokens.at(0)[len] == '{') // "server{"  || "server{sdfsd"
		{
			if (tokens.at(0).length() == (len + 1))  // "server{"
				tokens.erase(tokens.begin());
			if (tokens.at(0).length() > (len + 1))	// "server{FDSDFS"
				tokens.at(0) = tokens.at(0).substr((len + 1), tokens.at(0).length() - (len + 1));
		}
	}
	else
		return(1);
    return (0);
}
