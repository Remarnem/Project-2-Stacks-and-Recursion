// extraCredit.cpp
// Joshua Steege
// Section 2
// Last modified: 10/28/2021
#include <iostream>
#include <sstream>
#include "PostfixStack.h"

bool checkPrecedence(char first, char stackChar);

int main(int argc, char** argv) {

    // A string with the expression in reverse polish notation
    std::string postfixString;

    // Stack to store operands from infix expression
    // Will be reused later to solve infix expression
    PostfixStack aStack;

    // Loop starts at 1 because clion passes .exe path as first argument
    for (int i = 1; i < argc; ++i) {
        // Check if argv is an operation
        if (argv[i][0] == '*' || argv[i][0] == '/' || argv[i][0] == '+' || argv[i][0] == '-'
            || argv[i][0] == '(' || argv[i][0] == ')') {
            // Argv is an operation
            std::string operation = argv[i];
            // Check if argv should be added to the stack
            if (aStack.getSize() == 0 || operation[0] == '(') {
                // Argv MUST be added, either stack is empty, or it's the start of a parenthesis
                aStack.push(operation);
            } else if (operation[0] == ')') { // End of parenthesis
                // Loop until matching parenthesis is found
                while (aStack.top() != "(") {
                    // Add operations to end of string
                    postfixString.append(aStack.top());
                    postfixString.append(" ");
                    aStack.pop();
                }
                // Pop '(' from top of stack
                aStack.pop();
            } else { // Stack isn't empty, and operation isn't a parenthesis
                // Check if operation should be pushed or appended
                if (aStack.top() == "(") { // Top of stack is parenthesis
                    // Operation MUST be pushed onto stack
                    aStack.push(operation);
                } else if (checkPrecedence(operation[0], aStack.top()[0])) {
                    // Operation has higher precedence than what's on top of the stack, must be pushed.
                    aStack.push(operation);
                } else {
                    // Operation has lower or equal precedence to what's on top of the stack
                    // Loop until operation has higher precedence than what's on top of the stack or until stack is empty.
                    while (!checkPrecedence(operation[0], aStack.top()[0]) && aStack.getSize() != 0) {
                        // Add operation from top of stack to the end of postfixString
                        postfixString.append(aStack.top());
                        postfixString.append(" ");
                        // Remove operation from top of stack
                        aStack.pop();
                    }
                    // Operation now has higher precedence than what's on top of the stack, must be pushed.
                    aStack.push(operation);
                }
            }
        } else { // Argv isn't an operation, it must be operand
            // Adding argv to end of postfixString
            postfixString.append(argv[i]);
            postfixString.append(" ");
        }
    } // End of for loop
    // Making sure there's no extra operation left in the stack that need to be
    // appended to postfixString
    while (aStack.getSize() != 0) {
        postfixString.append(aStack.top());
        postfixString.append(" ");
        aStack.pop();
    }

    // postfixString now stores the converted expression

    // Displaying the original infix expression passed to the program
    std::cout << "Original string: ";
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }
    // Displaying the converted postfix expression
    std::cout << std::endl << "Converted string: " << postfixString << std::endl;

    // Adding postfixString to aStack for evaluation
    // Converting postfixString to an istream object
    std::istringstream iss(postfixString);
    // String to store an argument of postfixString
    std::string argument;

    // Separate arguments in postfixString by ' '
    while (std::getline(iss, argument, ' ')) {
        aStack.push(argument);
    }
    // aStack stores all arguments of postfixString
    std::cout << "The answer to \'" << postfixString << "\' is:" << std::endl;
    std::cout << aStack.evaluate() << std::endl;
}

// Returns true if first has higher precedence than stackChar,
// false if first has equal or lower precedence than stackChar
bool checkPrecedence(char first, char stackChar) {
    // One of the characters is a parenthesis
    // May not be necessary but will leave to be safe
    if (stackChar == '(' || stackChar == ')') {
        return false;
    } else if (first == '(' || first == ')') {
        return true;
    }

    // first is multiplication/division
    if (first == '*' || first == '/') {
        if (stackChar == '*' || stackChar == '/') { // Equal precedence, stack holds left most operation
            return false;
        } else { // stackChar must be either '+' or '-', first has higher precedence
            return true;
        }
    }

    // First is either '+' or '-', stackChar will always have equal or higher precedence than first
    return false;
}