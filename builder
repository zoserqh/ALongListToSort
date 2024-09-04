#!/bin/bash

mkdir bin
mkdir data

#compile listGenerator
cd sourceCode/listGenerator/
echo "compiling listGenerator"
g++ listGenerator.cpp -o ../../bin/listGenerator

#execute listGenerator -> list.txt
cd ../../bin/
echo "generating list.txt 75seg aprox"
./listGenerator
 
#compile sortDefaultCPP
cd ../sourceCode/sortDefaultCPP/
echo "compiling stlCPP"
g++ main.cpp -pthread -o ../../bin/stlCPP

#compile multiThreadingSortCPP
cd ../multiThreadingSortCPP
echo "compiling mtCPP"
g++ main.cpp -pthread -o ../../bin/mtCPP

echo "the builder has finished"
