#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./statistical_outlier_removal 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./statistical_outlier_removal 
fi

