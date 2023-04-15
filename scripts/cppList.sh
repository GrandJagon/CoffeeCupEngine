#!/bin/bash

# Generates the list of all cpp files within src folder to populate CMakeLists.txt
cd ../CoffeeCupEngine

for file in $(find src/ -maxdepth 9 -mindepth 1 -name "*.cpp");
do  
    echo "${file}"
done

for file in $(find utils/ -maxdepth 9 -mindepth 1 -name "*.cpp");
do  
    echo "${file}"
done