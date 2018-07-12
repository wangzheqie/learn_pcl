#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
#    ./cloud_viewer  object.ply
    ./cloud_viewer model.ply model.pcd 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./cloud_viewer  object.ply
fi

