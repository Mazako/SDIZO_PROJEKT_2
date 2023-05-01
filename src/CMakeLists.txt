cmake_minimum_required(VERSION 3.24)
project(SDIZO_GRAPHS)

set(CMAKE_CXX_STANDARD 17)
add_library(SDIZO_GRAPHS
        graph/matrix/MatrixGraph.h
        graph/matrix/MatrixGraph.cpp
        graph/list/ListGraph.cpp
        graph/list/ListGraph.h
        minimal_spanning_tree/disjoint_node/DisjointNode.cpp
        minimal_spanning_tree/disjoint_node/DisjointNode.h
        minimal_spanning_tree/MinimalSpanningTree.cpp
        minimal_spanning_tree/MinimalSpanningTree.h
        graph/edge/Edge.cpp
        graph/edge/Edge.h
        minimal_spanning_tree/prim_vertex/PrimVertex.cpp
        minimal_spanning_tree/prim_vertex/PrimVertex.h
        graph/Graph.cpp
        graph/Graph.h shortest_path/ShortestPath.cpp shortest_path/ShortestPath.h shortest_path/ShortestPath.h shortest_path/ShortestPath.cpp shortest_path/shortest_path_dto/ShortestPathDTO.cpp shortest_path/shortest_path_dto/ShortestPathDTO.h shortest_path/djikstra_vertex/DjikstraVertex.cpp shortest_path/djikstra_vertex/DjikstraVertex.h)
