#include "../include/utils.hpp"
#include "../include/scripts.hpp"
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cctype>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

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

void ExecFunctions::createProject(LangChoice &langChoice)
{
    try
    {
        if (&langChoice == NULL)
        {
            throw std::string("The langChoice parameter variable was not passed correctly.");
        }

        // Creating variables.
        std::string dirname;
        std::vector<std::string> folders;
        std::vector<std::string> files;
        // Ensure that vector's staying clear.
        folders.clear();
        files.clear();

        while (true)
        {
            std::cout << "[aefi-generator]:Enter the name of the project:";
            std::cin >> dirname;

            if (fs::exists(dirname))
            {
                std::cout << "To exit, press Ctrl-C and run program again." << std::endl;
                std::cout << "A project with the same name exists, enter a project that has not yet been created." << std::endl;
                continue;
            }

            break;
        }

        fs::create_directory(dirname);
        fs::current_path(dirname);

        switch (langChoice.choiceId)
        {
        case CPP:

            folders.push_back("include");
            folders.push_back("obj");
            folders.push_back("src");
            folders.push_back("obj");

            files.push_back("makefile");

            for (int i = 0; i < folders.size(); i++)
            {
                if (!fs::exists(folders[i]))
                {
                    std::cout << "[aefi-generator]:Creating folders... ->" << folders[i] << std::endl;
                    fs::create_directory(folders[i]);
                }
            }

            for (int i = 0; i < files.size(); i++)
            {
                if (!fs::exists(files[i]))
                {
                    std::ofstream file(files[i]);
                    file.close();
                }
            }

            break;
        case NODEJS:
            NODE::verifyDependencies();
            folders.push_back("config");
            folders.push_back("database");
            folders.push_back("routes");
            folders.push_back("controller");
            files.push_back("index.js");

            for (int i = 0; i < folders.size(); i++)
            {
                if (!fs::exists(folders[i]))
                {
                    std::cout << "[aefi-generator]:Creating folders...-> " << folders[i] << std::endl;
                    fs::create_directory(folders[i]);
                }
            }

            for (int i = 0; i < files.size(); i++)
            {
                if (!fs::exists(files[i]))
                {
                    std::ofstream file(files[i]);
                    file.close();
                }
            }

            break;
        case NODETS:
            NODE::verifyDependencies();
            folders.push_back("config");
            folders.push_back("database");
            folders.push_back("routes");
            folders.push_back("controller");
            folders.push_back("types");
            files.push_back("index.ts");

            for (int i = 0; i < folders.size(); i++)
            {
                if (!fs::exists(folders[i]))
                {
                    std::cout << "[aefi-generator]:Creating folders...-> " << folders[i] << std::endl;
                    fs::create_directory(folders[i]);
                }
            }

            for (int i = 0; i < files.size(); i++)
            {
                if (!fs::exists(files[i]))
                {
                    std::ofstream file(files[i]);
                    file.close();
                }
            }
            break;
        case C:
            folders.push_back("include");
            folders.push_back("obj");
            folders.push_back("src");
            folders.push_back("obj");

            files.push_back("makefile");

            for (int i = 0; i < folders.size(); i++)
            {
                if (!fs::exists(folders[i]))
                {
                    std::cout << "[aefi-generator]:Creating folders...:" << folders[i] << std::endl;
                    fs::create_directory(folders[i]);
                }
            }

            for (int i = 0; i < files.size(); i++)
            {
                if (!fs::exists(files[i]))
                {
                    std::ofstream file(files[i]);
                    file.close();
                }
            }

            break;
        default:
            throw std::string("Invalid language option.");
            break;
        }
    }
    catch (std::string &err)
    {
        std::cerr << std::endl
                  << PNAME_PREFIX_ERR << err << std::endl;
        std::exit(-1);
    }
}
