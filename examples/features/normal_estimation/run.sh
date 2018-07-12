#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./normal_estimation model.ply  model_sampling.ply
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./normal_estimation  model.ply model_sampling.ply
fi

