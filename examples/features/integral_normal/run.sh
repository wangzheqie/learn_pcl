#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
#    ./integral_normal model.ply  model_sampling.ply
    ./integral_normal table.pcd 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
#    ./integral_normal  model.ply model_sampling.ply
    ./integral_normal table.pcd 
fi

