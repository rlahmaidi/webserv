#include "tools_cpp.hpp"

int find_del(std::string str, int del)
{
    int i;
    int j;

    i = -1;
    j = 0;
    while ((i = str.find(del, i+1)) != std::string::npos)
        j++;
    return (j);
}
