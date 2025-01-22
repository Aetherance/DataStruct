#!/bin/zsh
g++ test1.cpp -o output/std::Stack
g++ test2.cpp -o output/MyStack
echo std::stack:
./output/std::Stack

echo
echo MyStack:
./output/MyStack
echo