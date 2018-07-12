#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./girl_icp.cpp Depth_0000.ply 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./girl_icp.cpp
fi

