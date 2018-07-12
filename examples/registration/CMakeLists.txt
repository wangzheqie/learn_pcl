cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(girl_icp.cpp)

find_package(PCL 1.7 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (girl_icp.cpp girl_icp.cpp)
target_link_libraries (girl_icp.cpp ${PCL_LIBRARIES})
