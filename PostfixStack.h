// PostfixStack.h
// Joshua Steege
// Section 2
// Last modified: 10/26/2021

#ifndef PROJECT_2_STACKS_AND_RECURSION_POSTFIXSTACK_H
#define PROJECT_2_STACKS_AND_RECURSION_POSTFIXSTACK_H

#include <iostream>

class PostfixStack {
private:
    std::string *stack;
    size_t capacity;
    size_t size;
public:
    explicit PostfixStack(size_t capacity = 50);
    virtual ~PostfixStack();
    void setCapacity(size_t capacity);
    bool push(std::string data);
    bool pop();
    std::string top();
    size_t getSize() const;
    double evaluate();
    void emptyStack();
};


#endif //PROJECT_2_STACKS_AND_RECURSION_POSTFIXSTACK_H
