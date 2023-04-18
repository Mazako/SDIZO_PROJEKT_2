#ifndef SDIZO_PROJEKT_2_MATRIXGRAPH_H
#define SDIZO_PROJEKT_2_MATRIXGRAPH_H
#include <iostream>
#include <string>

class MatrixGraph {
    int v;
    int **array;
public:
    MatrixGraph(int v);

    ~MatrixGraph();

    void addEdge(int v1, int v2, int weight);

    std::string toString();
};


#endif //SDIZO_PROJEKT_2_MATRIXGRAPH_H
