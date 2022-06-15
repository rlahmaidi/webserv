#include "tools_cpp.hpp"

// Ressource:
// std::getline() : https://m.cplusplus.com/reference/string/string/getline/


void parsingConfigFile(char *arg, std::vector<ServerBlock> &servers)
{
	std::string line;
	std::vector<std::string> tokens;
	std::ifstream config_file;
	std::vector<std::string> loc;
	size_t server_id;
	ServerBlock newServer;
	LocationBlock newLocation;

	config_file.open(arg, std::ifstream::in);

	if (config_file.is_open())
	{
		// use seekg() to go til the end of the file
		config_file.seekg(0, std::ifstream::end);
		if (config_file.tellg() == 0)
		{
			std::cout << "Error: Empty File" << std::endl;
			throw 2;
		}
		else
		{
			config_file.seekg(0, std::ifstream::beg); //  BEG
			while (getline(config_file, line))
			{
				if(line[line.size() == ';'])
								line.resize(line.size() - 1);
				tokens = split_line_to_tokens(line);// ; should be removed before split
				if (tokens.empty()) // "to pass empty line  "
					continue;
				else if (tokens.at(0).substr(0, 6) == "server") // "server" "{sdf" || "server{ghfs"
				{
					if (checkForAcoladeServ(tokens, 6) == 0)
					{

						if (tokens.empty() == false) // "server{listen 80;"
						{
							if (fill_server(tokens, newServer)) // error == 1
								throw 1;
						}
						while (getline(config_file, line)) // loop inside server block;
						{
							if(line[0] == '}')
								break;
							if(line[line.size() == ';'])
								line.resize(line.size() - 1); // to remove the ";";
							tokens = split_line_to_tokens(line);// ; should be removed before split
							if (tokens.empty()) // "to pass empty line  "
								continue;
							if (tokens.at(0) == "location")
							{
								
								tokens.erase(tokens.begin());						   // I erase the location token from the vector
								if (checkForAcoladeLocation(tokens, newLocation) == 0) // newServer
								{
									if (tokens.empty() == false) // "server{listen 80;"
									{
										if (fill_server(tokens, newServer)) // error == 1
											throw 1;
									}
									while (getline(config_file, line))
									{
										// LOOP INSIDE YOUR LOCATION BLOCK;
										// if(line[line.length() - 1] == '}')
										// 	break;
										if(line[0] == '}')
											break;
										if(line[line.size() == ';'])
											line.resize(line.size() - 1); // to remove the ";";
										tokens = split_line_to_tokens(line);// ; should be removed before split
										if (tokens.empty()) // "to pass empty line  "
											continue;
										fill_location(tokens, newLocation);
									}
								}
								else
									throw 5;
							}
							else
							{
								if (fill_server(tokens, newServer)) // error  == 1
									throw 1;
							}

						} // end of loop over server;
						servers.push_back(newServer);
					}
					else // in case mal9atch acolade dial SERRRVER
						throw 5;
				}
				else
					throw 5;
				//   ------------------------------
				char *cstr = new char[line.length() + 1];
				std::strcpy(cstr, line.c_str());

				// cstr now contains a c-string copy of str

				// char * p = std::strtok (cstr,"	 ;");
				//  while (p!=0)
				//  {											I COMMENTED THIS IMAN'S LOOP
				//  	std::cout << p << "|\n";
				//  	//p = std::strtok(NULL," ");
				//  }
				//  ----------------------------------------------
				server_id++;
			}
			std::vector<std::string>::iterator iter;
			for (iter = tokens.begin(); iter != tokens.end(); ++iter)
			{
				std::cout << *iter << std::endl;
				std::cout << "here here here" << std::endl;
			}

			// Printing the token vector
			// for (size_t i = 0; i < tokens.size(); i++)
			//	std::cout << tokens[i] << std::endl;
			// {
			// 	// 1- first thing to do is split to tokens
			// 	// expect "server" then "{"

			// 	if (line == "server")
			// 	servers.push_back(parserServerBlock(config_file, line));
			// 	else
			// 		throw 5;

			servers.push_back(newServer);
		}
	}
	else
	{
		std::cout << "Error: Opening File" << std::endl;
		throw 5;
	}
}