#ifndef SDIZO_PROJ_2_GRAPH_H
#define SDIZO_PROJ_2_GRAPH_H
#include <string>
#include <vector>
#include "graph/edge/Edge.h"
class Graph {
public:
    virtual void addEdge(int v1, int v2, int weight) = 0;
    virtual int getWeight(int v1, int v2) = 0;
    virtual bool isDirected() = 0;
    virtual int getV() = 0;
    virtual std::string toString() = 0;
    virtual std::vector<std::pair<int, int>> getNeighbours(int v) = 0;
    virtual std::vector<Edge> getEdges() = 0;
};


#endif
