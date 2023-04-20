cmake_minimum_required(VERSION 3.24)
project(SDIZO_GRAPHS)

set(CMAKE_CXX_STANDARD 17)
add_library(SDIZO_GRAPHS
        graph/matrix/MatrixGraph.h
        graph/matrix/MatrixGraph.cpp
        graph/list/ListGraph.cpp
        graph/list/ListGraph.h
        shortest_path/vertex_addiitional_info/VertexAdditionalInfo.cpp
        shortest_path/vertex_addiitional_info/VertexAdditionalInfo.h minimal_spanning_tree/disjoint_node/DisjointNode.cpp minimal_spanning_tree/disjoint_node/DisjointNode.h minimal_spanning_tree/MinimalSpanningTree.cpp minimal_spanning_tree/MinimalSpanningTree.h graph/edge/Edge.cpp graph/edge/Edge.h)
