#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./passthrough  model.pcd model_cropped.pcd 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./passthrough 
fi

