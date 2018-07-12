#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./resampl  object.ply
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./resampl object.ply
fi

