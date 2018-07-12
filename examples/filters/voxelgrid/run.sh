#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./voxel_grid  model.ply
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./voxel_grid  model.ply
fi

