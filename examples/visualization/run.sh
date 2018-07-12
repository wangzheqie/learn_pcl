#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./plane_seg  0
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./plane_seg  0
fi

