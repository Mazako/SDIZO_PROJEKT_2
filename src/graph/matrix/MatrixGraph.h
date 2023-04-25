#ifndef SDIZO_PROJEKT_2_MATRIXGRAPH_H
#define SDIZO_PROJEKT_2_MATRIXGRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include "graph/edge/Edge.h"
#include "graph/Graph.h"

class MatrixGraph : public Graph {
    int v;
    int **array;
    bool directed;
public:
    MatrixGraph(int v, bool directed);

    ~MatrixGraph();

    void addEdge(int v1, int v2, int weight) override;

    std::string toString() override;

    bool isDirected() override;

    int getWeight(int v1, int v2) override;

    int getV() override;

    std::vector<Edge> getEdges() override;

    std::vector<std::pair<int, int>> getNeighbours(int v) override;

};


#endif //SDIZO_PROJEKT_2_MATRIXGRAPH_H
