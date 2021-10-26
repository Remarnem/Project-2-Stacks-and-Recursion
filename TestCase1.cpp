// PostfixStack.cpp
// Joshua Steege
// Section 2
// Last modified: 10/26/2021

#include "PostfixStack.h"
#include <iostream>

int main() {
    // Creating stack
    PostfixStack testStack;

    // Test push function
    std::cout << "Testing push function..." << std::endl;
    std::cout << "push(\"a\")" << std::endl;
    testStack.push("a");
    std::cout << "push(\"b\")" << std::endl;
    testStack.push("b");
    std::cout << "push(\"c\")" << std::endl;
    testStack.push("c");

    // Test top() function
    std::cout << "top() output: " << testStack.top() << std::endl;

    // Testing bad call of evaluate() function
    std::cout << std::endl << "Attempting to call evaluate() function without proper postfix stored in stack:" << std::endl;
    std::cout << "Output: " << testStack.evaluate() << std::endl;
    std::cout << "Checking top() after evaluate(): " << testStack.top() << std::endl;

    // Emptying stack
    std::cout << std::endl << "Calling emptyStack() function" << std::endl;
    testStack.emptyStack();
    std::cout << "Current size: " << testStack.getSize() << std::endl;

    // Evaluating expression with invalid operation
    std::cout << std::endl << "Evaluating expression with invalid operation..." << std::endl;
    std::cout << "Testing evaluate with the expression: '8 4 no'" << std::endl;
    testStack.push("8");
    testStack.push("4");
    testStack.push("no");
    std::cout << "Output: " << testStack.evaluate() << std::endl;

    // Testing resizing stack
    std::cout << std::endl << "Changing capacity with elements in stack..." << std::endl;
    std::cout << "Emptying stack..." << std::endl;
    testStack.emptyStack();
    std::cout << "Adding elements '1 7 9 15 11' to the stack" << std::endl;
    testStack.push("1");
    testStack.push("7");
    testStack.push("9");
    testStack.push("15");
    testStack.push("11");
    std::cout << "Size: " << testStack.getSize() << std::endl;
    std::cout << "Changing capacity to 4" << std::endl;
    testStack.setCapacity(4);
    std::cout << "Size after capacity change: " << testStack.getSize() << std::endl;
    std::cout << "Stack: " << std::endl;
    for (int i = testStack.getSize(); i > 0; --i) {
        std::cout << testStack.top() << std::endl;
        testStack.pop();
    }



}