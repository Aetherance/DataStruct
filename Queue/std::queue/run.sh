#!/bin/zsh
g++ test1.cpp -o output/std
g++ test2.cpp -o output/My
echo std:
./output/std

echo
echo my:
./output/My
echo