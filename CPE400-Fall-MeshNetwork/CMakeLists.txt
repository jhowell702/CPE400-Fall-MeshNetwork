# CMakeList.txt : CMake project for CPE400-Fall-MeshNetwork, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CPE400-Fall-MeshNetwork "src/CPE400-Fall-MeshNetwork.cpp" "inc/CPE400-Fall-MeshNetwork.h" "inc/graph_node.h" "inc/graph_connection.h"  "src/graph_connection.cpp" "inc/graph.h" "src/graph.cpp" "src/graph_node.cpp" "inc/command_utilities.h" "src/command_utilities.cpp")

# TODO: Add tests and install targets if needed.
include_directories(inc)
set (CMAKE_CXX_STANDARD 11)
