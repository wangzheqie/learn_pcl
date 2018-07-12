#!/bin/bash

if [ -d "build" ]; then 
    echo "have"
    cd build 
    cmake ..
    make 
    ./correspondence_grouping  milk.pcd milk_carton_all_small_clorox.pcd 
else
    echo "not have"
    mkdir build 
    cd build
    cmake ..
    make 
    ./correspondence_grouping  milk.pcd milk_carton_all_small_clorox.pcd 
fi

