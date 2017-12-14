#!/bin/bash
rm -rf mylibs
mkdir build
cd build
rm -rf *
cmake ..
make 
make install 

cd ..
./test.py
