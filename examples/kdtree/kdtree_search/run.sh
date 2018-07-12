#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./kdtree_search  model.ply
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./kdtree_search  model.ply
fi

