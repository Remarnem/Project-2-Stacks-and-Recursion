cmake_minimum_required(VERSION 3.20)
project(Project_2_Stacks_and_Recursion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_2_Stacks_and_Recursion main.cpp PostfixStack.cpp PostfixStack.h)
add_executable(TestCase1 TestCase1.cpp PostfixStack.cpp PostfixStack.h)
add_executable(ExtraCredit extraCredit.cpp PostfixStack.cpp PostfixStack.h)
