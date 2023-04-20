#ifndef SDIZO_PROJEKT_2_MATRIXGRAPH_H
#define SDIZO_PROJEKT_2_MATRIXGRAPH_H
#include <iostream>
#include <string>
#include <vector>
#include "graph/edge/Edge.h"

class MatrixGraph {
    int v;
    int **array;
    bool directed;
public:
    MatrixGraph(int v, bool directed);

    ~MatrixGraph();

    void addEdge(int v1, int v2, int weight = 1);

    std::string toString();

    bool isDirected();

    int getWeight(int v1, int v2);

    int getV() const;

    std::vector<Edge> getEdges();


};


#endif //SDIZO_PROJEKT_2_MATRIXGRAPH_H
