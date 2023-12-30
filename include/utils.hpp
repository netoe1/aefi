#ifndef UTILS_HPP
#define UTILS_HPP
// Including libraries
#include <string>

//  Defining prefixes:
#define PNAME_PREFIX_ERR "[aefi-err]:"
#define PNAME_PREFIX_FINE "[aefi-fine]:"

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

std::string toLowerCase(const std::string &str);

// Função para converter uma string para maiúsculas
std::string toUpperCase(const std::string &str);
#endif
