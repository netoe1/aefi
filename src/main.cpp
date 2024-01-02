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
                std::exit(SUCCESS);
            }

            if (function_str == "--about" ||
                function_str == "--abt" ||
                function_str == "about" ||
                function_str == "/abt" ||
                function_str == "/about")
            {
                about();
                std::exit(SUCCESS);
            }
        }

        if (argc == 3)
        {

            if (&argv[2] == NULL)
            {
                throw std::string("You didn't provide the language for generate project.");
            }
            function_str = argv[1];

            if (function_str == "create" || function_str == "--create" || function_str == "/create")
            {
                flag_str = argv[2];
                cliSetEnum_lang(flag_str, userChoice);

                ExecFunctions::createProject(userChoice);
            }
        }

        throw std::string("Invalid syntax, check --help for see valid commands.");
    }
    catch (string msg)
    {
        cout << PNAME_PREFIX_ERR << msg << endl;
        std::exit(ERROR);
    }
    return 0;
}

void help()
{
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
            throw std::string("The language that you set isn't supported yet or doesn't exist.");
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
            choice.choiceId = UNDEFINED;
            choice.language_as_str = "undefined";
            throw std::string("You provide an language that's not supported by cli.");
        }
    }

    catch (std::string &msg)
    {
        cerr << PNAME_PREFIX_INTERNAL << msg << std::endl;
        std::exit(ERROR);
    }
}
void about()
{
    cout << "This software was made by Ely Neto (netoe1_)." << endl;
    cout << "Here, our proposal is to make life easier for the programmer, to create new programs.\nAll of this software also has a study proposal for professionals involved in the project, it is a way of evolving intellectually." << endl;
}