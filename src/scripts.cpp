#include "../include/scripts.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <string>

void NODE::verifyDependencies()
{
    try
    {

        std::string ret = "";
        std::cout << "Verifying dependencies..." << std::endl;
        if (VERIFY_NODE != TERM_FINE)
        {
            ret = "nodeSDK is not installed on your machine, or was not recognized in the OS PATH variable.";
        }

        if (VERIFY_NPM != TERM_FINE)
        {
            ret += "\nnpmSDK is not installed on your machine, or was not recognized in the OS PATH variable.";
        }

        if (ret != "")
        {
            throw ret;
        }

        std::cout << "All dependencies are fine!" << std::endl;
    }
    catch (std::string &err)
    {
        std::cerr << std::endl
                  << PNAME_PREFIX_ERR << err
                  << std::endl;
        std::exit(ERROR);
    }
}

void TSNODE::verifyDependencies()
{
    try
    {

        std::string ret = "";
        std::cout << "Verifying dependencies..." << std::endl;
        if (VERIFY_NODE != TERM_FINE)
        {
            ret = "nodeSDK is not installed on your machine, or was not recognized in the OS PATH variable.";
        }

        if (VERIFY_NPM != TERM_FINE)
        {
            ret += "\nnpmSDK is not installed on your machine, or was not recognized in the OS PATH variable.";
        }

        if (VERIFY_TSNODE != TERM_FINE)
        {
            ret += "\nNodeSDK and tsnode package are not installed on your machine, or was not recognized in the OS PATH variable.";
        }

        if (ret != "")
        {
            throw ret;
        }

        std::cout << "All dependencies are fine!" << std::endl;
    }
    catch (std::string &err)
    {
        std::cerr << std::endl
                  << PNAME_PREFIX_ERR << err
                  << std::endl;
        std::exit(ERROR);
    }
}