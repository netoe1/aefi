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

// General variables...

string argument_fn;
string flag;

// Functions prototype declaration.

void help(); // Help function for CLI.


// Usage
// <program> <function> <language>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    try
    {
        // Testing first, commands without arguments;

        if (argc == 2)
        {
        }
    }
    catch (string &msg)
    {
        cout << PNAME_PREFIX_ERR << msg << endl;
    }
    return 0;
}

void help()
{
    cout << endl;
    cout << "[aefi-help]: Valid functions :" << endl;
    cout << "\t\t--help || -h \t-- Show valid commands to use" << endl;
    cout << "\t create <lang> \t Create an project in the same program's directory" << endl;
}
