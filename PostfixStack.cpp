// PostfixStack.cpp
// Joshua Steege
// Section 2
// Last modified: 10/26/2021

#include "PostfixStack.h"

// Constructor, default capacity of 50
PostfixStack::PostfixStack(size_t capacity) {
    this->capacity = capacity;
    size = 0;
    stack = new std::string[capacity];
}

// Destructor
PostfixStack::~PostfixStack() {
    delete stack;
}

// Sets the capacity of the stack to the passed number and copy data over to the new stack
void PostfixStack::setCapacity(size_t capacity) {
    if (size == 0) { // Stack is empty
        delete stack;
        stack = new std::string[capacity];
    }
    // Save old values
    std::string *oldStack = stack;
    size_t oldSize = size;
    // Create array with new capacity
    stack = new std::string[capacity];
    size = 0;
    this->capacity = capacity;
    // Transfer values from old array to new one until either all are transferred or capacity runs out
    for (int i = 0; i < oldSize && i < capacity; ++i) {
        stack[i] = oldStack[i];
        size++;
    }
    delete oldStack;
    oldStack = nullptr;
}

// Adds the passed data to the top of the stack, returns false if it can't, true if it does.
bool PostfixStack::push(std::string data) {
    // Check if stack is full
    if (capacity == size) {
        return false;
    }
    // Increment stack size
    size++;
    // Add data to end of stack
    stack[size - 1] = data;
    return true; // Data successfully added
}

// Removes the top element of the stack, returns true if it does.
bool PostfixStack::pop() {
    // Check if stack is empty
    if (size == 0) {
        return false; // Nothing to pop
    }
    size--;
    return true; // Successfully removed top
}

// Returns the value of the top element of the stack without popping/removing it.
std::string PostfixStack::top() {
    // Check if stack is empty
    if (size == 0) {
        return "NULL"; // Function must return something
    }
    return stack[size - 1];
}

// Returns the size of the stack
size_t PostfixStack::getSize() const {
    return size;
}

// Recursive function to evaluate postfix string stored in the stack.
double PostfixStack::evaluate() {
    // Check if stack is empty
    if (size == 0) {
        return -1; // Empty stack, improper function call.
    }
    // Get the operator to perform
    char operation = top()[0]; // Gets the first character of the top string
    pop();

    // Check if the second operand needs a recursive call
    double operand2;
    // Check if next argument is operation
    if (top() == "*" || top() == "/" || top() == "+" || top() == "-") {
        operand2 = evaluate();
    } else { // Isn't operation
        try { // Check if top() is a double
            operand2 = std::stod(top());
            pop();
        } catch (std::invalid_argument &e1) { // top() isn't a double
            std::cout << "[ERROR]: top() \"" << top() << "\" can't be parsed by stod(), returning -1" << std::endl;
            return -1;
        }
    }

    // Check if the first operand needs a recursive call
    double operand1;
    // Check if next argument is operation
    if (top() == "*" || top() == "/" || top() == "+" || top() == "-") {
        operand1 = evaluate();
    } else { // Isn't operation
        try { // Check if top() is a double
            operand1 = std::stod(top());
            pop();
        } catch (std::invalid_argument &e1) { // top() isn't a double
            std::cout << "[ERROR]: top() \"" << top() << "\" can't be parsed by stod(), returning -1" << std::endl;
            return -1;
        }
    }

    // Switch to perform proper operation and return the value
    switch (operation) {
        case '*':
            return operand1 * operand2;
            break;
        case '/':
            return operand1 / operand2;
            break;
        case '+':
            return operand1 + operand2;
            break;
        case '-':
            return operand1 - operand2;
            break;
        default: // In case operation isn't what's expected
            std::cout << "[ERROR]: Something went wrong determining what the operator is." << std::endl;
            std::cout << "[ERROR]: Passed '" << operation << "' Expected: '*', '/', '+', or '-'" << std::endl;
    }
    return -1; // Error occurred
}

// Removes all elements in the stack
void PostfixStack::emptyStack() {
    delete stack;
    stack = new std::string[capacity];
    size = 0;
}
