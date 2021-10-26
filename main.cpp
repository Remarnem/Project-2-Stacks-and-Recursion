// main.cpp
// Joshua Steege
// Section 2
// Last modified: 10/26/2021

#include <iostream>
#include "PostfixStack.h"

int main(int argc, char** argv) {
    /*
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv[0]: " << argv[0] << std::endl;
     */

    PostfixStack myStack;
    // Loop starts at 1 because clion passes .exe path as first argument
    for (int i = 1; i < argc; ++i) {
        myStack.push(argv[i]);
    }
    std::cout << "The result is:" << std::endl;
    std::cout << myStack.evaluate() << std::endl;

    return 0;
}
