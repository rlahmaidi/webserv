#include "tools_cpp.hpp"

int    fill_server(std::vector<std::string> tokens,ServerBlock& newServer)
{
   
    
    std::vector<std::string>    tmp;
    	
        if(tokens.at(0).compare("listen")  == 0)
        {  // can listen be exist but without parametre?
            // i sow somewhere that the hos/port may be followed by defaul_serve, i need to ask about it;
           tmp = split_token_with_del(tokens.at(1), ':');
            if(tmp.size() == 2)
            {
                newServer.host = tmp.at(0);
                newServer.port = atoi(tmp.at(1).c_str());
                return(0);
            }
            else if(tokens.size() == 1)
            {
                newServer.port = atoi(tmp.at(0).c_str());
                return(0);
            }
            else
                return(1);
        }
        else if(tokens.at(0).compare("serve_name") == 0)
        {
            tokens.erase(tokens.begin());
            newServer.server_names = tokens;
            // still need a test to see if the assignement operator is working;
            return(0);
        }
        else if(tokens.at(0).compare("root")  == 0)
        {
            if(tokens.size() == 2)
            {
                newServer.root = tokens.at(1);
                return(0);
            }
            else
                return(1);
        }
        else if(tokens.at(0).compare("index")  == 0)
        {
            tokens.erase(tokens.begin());
            newServer.index = tokens;
            // still need a test to see if the assignement operator is working;
            return(0);
        }
        else if(tokens.at(0).compare("error_pages")  == 0)
        {
            
        }
        // else if(tokens.at(0).compare("request_method")  == 0)
        // {
            
        // }
        else if(tokens.at(0).compare("autoindex")  == 0)
        {
            if(tokens.size() == 2 && (!tokens.at(1).compare("on") || !tokens.at(1).compare("of")))
            {
                newServer.root = tokens.at(1);
                return(0);
            }
            else
                return(1);
        }
        else if(tokens.at(0).compare("client_max_body_size")  == 0)
        {
            if(tokens.size() == 2)
            {
                //tokens.resize(tokens.size() - 1); atoi will take the numbe without the M;
                newServer.client_max_body_size =  atoi(tokens.at(1).c_str()) * 1048576;
                return(0);
            }
            else
                return(1);
        }
        // other else if will be added here later;
        else
            throw 6;
}

int   fill_location(std::vector<std::string>loc, LocationBlock& newLocation)
{

}