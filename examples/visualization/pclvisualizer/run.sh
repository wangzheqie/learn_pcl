#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./pclvisualizer  object.ply
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./pclvisualizer  object.ply 
fi

