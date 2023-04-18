cmake_minimum_required(VERSION 3.24)
project(SDIZO_GRAPHS)

set(CMAKE_CXX_STANDARD 17)
add_library(SDIZO_GRAPHS
        graph/matrix/MatrixGraph.h
        graph/matrix/MatrixGraph.cpp graph/list/ListGraph.cpp graph/list/ListGraph.h)
