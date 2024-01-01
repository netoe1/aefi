#include "../include/utils.hpp"
#include <string>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <cctype>

std::string toLowerCase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Função para converter uma string para maiúsculas
std::string toUpperCase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// void createProject(const int &language)
// {
//     char op = '0';
//     while (tolower(op) != 'y' || tolower(op) != 'n')
//     {
//         std::cout << "Do you want to create a project [y/n]:";
//         std::cin >> op;
//         switch (op)
//         {
//         case 'y':
//             break;
//         case 'n':
//             break;
//         default:
//             std::cout << "Please, provide a valid i/o option." << std::endl;
//             break;
//         }
//     }
// }
