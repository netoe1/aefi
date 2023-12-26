// Native tools

#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <cstring>
#include <exception>
// External tools
#include "../include/utils.hpp"

using std::cout,
    std::string,
    std::setlocale,
    std::cerr,
    std::endl;
string argument_fn;
string flag;

// <program> <function> <language>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    try
    {
        if (argc != 3)
        {
                }
    }
    catch (string &msg)
    {
        cout << PNAME_PREFIX_ERR << msg << endl;
    }
    return 0;
}
