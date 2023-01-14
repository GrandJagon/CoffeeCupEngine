#!/bin/bash

# Build all the cpp files into a shared linux shared library .so



for file in $(find src/ -maxdepth 9 -mindepth 1 -name "*.cpp");
do  
    x=${file##*/}
    y=${x%.*}
    g++ -fpic -c "$file" -o build/"$y".o
done
