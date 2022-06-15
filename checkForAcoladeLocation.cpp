#include "tools_cpp.hpp"

int checkForAcoladeLocation(std::vector<std::string>& tokens, LocationBlock& newLocation)
{
	//if (tokens.at(0).substr(0, len) == "server")			// "PATH" "{sdf" || "PATH{ghfs"
	//{
		// Check for {
			
		// if(aco = find(tokens(0), '{') == pos) // "PATH" "{sdf"
		/*
			newLocation.path = tokens(0);
			"{"
			
		*/
		// else									// "PATH{sdfs"
		/*
			newLocation.path = tokens.at(0).substr(0, aco); 
		*/

		if (tokens.at(0).length() == len)  // "PATH" "{dfgdfgdf"
		{
			if (tokens.at(1)[0] == '{' && tokens.at(1).length() > 1) // "PATH" "{FDSDFS"
					tokens.at(1) = tokens.at(1).substr(1, tokens.at(1).length() - 1);
			else
				return (1);
		}
		else if (tokens.at(0).length() >= (len + 1) && tokens.at(0)[len] == '{') // "PATH{"  || "PATH{sdfsd"
		{
			if (tokens.at(0).length() == (len + 1))  // "PATH{"
				tokens.erase(tokens.begin());		// SPLIT WITH CHARACTER
			if (tokens.at(0).length() > (len + 1))	// "PATH{FDSDFS"
				tokens.at(0) = tokens.at(0).substr((len + 1), tokens.at(0).length() - (len + 1));   /// SPLIT WITH CHARACTER
		}
	//}
	//else
	//	return(1);
    return (0);
}