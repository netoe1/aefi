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

void setupVariables();
void help(); // Help function for CLI.

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    try
    {
        if (argc != 3)
        {
            throw "You set an invalid type of parameters."
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
