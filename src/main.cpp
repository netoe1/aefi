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
LangChoice userChoice; // Function about create.

// Functions prototype declaration.
void help();  // Help function for CLI.
void about(); // About function for CLI.
bool ensureCreateProject(std::string &flag);
void cliSetEnum_lang(std::string &lang, LangChoice &choice);

// void cliSetEnum_function(std::string &lang, LangChoice &choice_struct);
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

            if (function_str == "--about" ||
                function_str == "--abt" ||
                function_str == "about" ||
                function_str == "/abt" ||
                function_str == "/about")
            {
                about();
            }

            throw std::string("Invalid syntax, check valid commands (--help)!");
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
                flag_str = argv[2];
                cliSetEnum_lang(flag_str, userChoice);

                switch (userChoice.choiceId)
                {
                case CPP:
                    cout << endl
                         << "You choose cpp!" << endl;
                    break;
                case C:
                    cout << endl
                         << "You choose cpp!" << endl;
                    break;
                case NODEJS:
                    cout << endl
                         << "You choose nodejs!" << endl;
                    break;
                case NODETS:
                    cout << endl
                         << "You choose tsnode!" << endl;
                    break;
                default:
                    break;
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
void cliSetEnum_lang(std::string &lang, LangChoice &choice)

{
    try
    {
        if (lang.empty())
        {
            throw std::string("You didn't pass an valid parameter in cliSetEnum_lang() function.");
        }

        lang = toLowerCase(lang);

        if (lang == OPTION_C)
        {
            choice.choiceId = C;
            choice.language_as_str = std::string(OPTION_C);
        }
        else if (lang == OPTION_NODE)
        {
            choice.choiceId = NODEJS;
            choice.language_as_str = std::string(OPTION_NODE);
        }
        else if (lang == OPTION_TSNODE)
        {
            choice.choiceId = NODETS;
            choice.language_as_str = std::string(OPTION_C);
        }
        else if (lang == OPTION_CPLUS_1 || lang == OPTION_CPLUS_2)
        {
            choice.choiceId = CPP;
            choice.language_as_str = std::string(OPTION_C);
        }
        else
        {
            throw std::string("You provide an language that's not supported by cli.");
        }
    }

    catch (std::string &msg)
    {
        cout << endl;
        cerr << PNAME_PREFIX_INTERNAL << msg;
    }
}
void about()
{
}