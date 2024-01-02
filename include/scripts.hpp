#ifndef SCRIPTS_HPP
#define SCRIPTS_HPP
#include <cstdlib>

#define VERIFY_NPM system("npm -v")
#define VERIFY_NODE system("node -v")
#define VERIFY_TSNODE system("tsnode --version")

// typedef enum Dependencies
//{
//     NODESDK,
//     NPMSDK,
//    GCC,
//    CLANG
//} DependenciesVerify;

namespace NODE
{
    void verifyDependencies();
}

namespace TSNODE
{
    void verifyDependencies();
}

#endif