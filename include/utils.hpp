#ifndef UTILS_HPP
#define UTILS_HPP
// Including libraries
#include <string>
#include <cstdlib>
//  Defining prefixes:
#define PNAME_PREFIX_ERR "[aefi-err]:"
#define PNAME_PREFIX_FINE "[aefi-fine]:"
#define PNAME_PREFIX_INTERNAL "[aefi-internal-err]:"

//  Defining labels as a CLI function

#define FN_CLI_LABEL_HELP_LONG "--help"
#define FN_CLI_LABEL_HELP_SHORT "-h"
#define FN_CLI_LABEL_CREATE_LONG "create"

//  Defining options:
#define OPTION_TSNODE "nodets"
#define OPTION_NODE "nodejs"
#define OPTION_C "c"
#define OPTION_CPLUS_1 "c++"
#define OPTION_CPLUS_2 "cpp"

//  Exit

#define SUCCESS 0
#define ERROR -1
#define TERM_FINE 0
#define TERM_ERR 1

//  Macros

#if __linux__
#define clearTerm() system("clear")
#elif _WIN32
#define clearTerm() system("cls")
#endif
// Static classes

class ExecFunctions
{
public:
    static void createProject(LangChoice &LangChoice);
};

std::string toLowerCase(const std::string &str);

// Função para converter uma string para maiúsculas
std::string toUpperCase(const std::string &str);

typedef enum cli_lang
{
    C,
    CPP,
    NODEJS,
    NODETS
} CLI_LANGUAGES;

typedef enum cli_functions
{
    HELP,
    CREATE,
    ABOUT
} CLI_FUNCTIONS;

typedef struct choice
{
    int choiceId;
    std::string language_as_str;
} LangChoice;

#endif
