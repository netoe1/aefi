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

string function_str;
string flag_str;

// Functions prototype declaration.
void help(); // Help function for CLI.
bool ensureCreateProject(std::string &flag);
// Correct usage
// <program> <function> <argument>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    try
    {
        if (argc < 2 || argc > 3)
        {
            throw std::string("You got less or more arguments than necessary, check --help for correct usage.");
        }

        // Testing first, commands without arguments;

        if (argc == 2 && argv[1] != NULL)
        {
            function_str = argv[1];
            if (
                function_str == "--help" ||
                function_str == "-h" ||
                function_str == "/h" ||
                function_str == "/help")
            {
                help();
            }
            return SUCCESS;
        }

        if (argc == 3)
        {

            if (argv[2] == nullptr)
            {
                throw std::string("You didn't provide the language for generate project.");
            }
            function_str = argv[1];

            if (function_str == "create")
            {

                if (flag_str == OPTION_NODE)
                {
                }
                else if (flag_str == OPTION_C)
                {
                }
                else if (flag_str == OPTION_CPLUS_1 || flag_str == OPTION_CPLUS_2)
                {
                }

                throw std::string("Probably you set an invalid language supported for generate an skeleton.");
            }
        }

        throw std::string("Invalid syntax, check --help for see valid commands.");
    }
    catch (string msg)
    {
        cout << PNAME_PREFIX_ERR << msg << endl;
    }
    return 0;
}

void help()
{
    cout << endl;
    cout << "[aefi-help]: Valid functions:" << endl;
    cout << "--help || -h \t-- Show valid commands to use" << endl;
    cout << "create <lang> \t-- Create an project in the same program's directory" << endl;
    cout << endl;
    cout << "SUPPORTED LANGUAGES:" << endl;
    cout << "C\t--\tGenerate a template for C programs. (type c in <lang> arg)" << endl;
    cout << "C++\t--\tGenerate a template for C++ programs. (type cpp or c++ in <lang> arg)" << endl;
    cout << "Nodejs\t--\tGenerate a template of Nodejs projects. (type nodejs in arg)" << endl;
    cout << "Nodets\t--\tGenerate a template of Nodets projects. (type nodets in arg)" << endl;
}

bool mayCreateProject(bool choice, std::string &language)
{
    try
    {
    }
    catch (std::string &err)
    {
        cerr << PNAME_PREFIX_ERR << err << endl;
    }
}
