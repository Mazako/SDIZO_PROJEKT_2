#ifndef SDIZO_PROJ_2_LISTGRAPH_H
#define SDIZO_PROJ_2_LISTGRAPH_H

#include <string>
#include <vector>
#include "graph/edge/Edge.h"
#include "graph/Graph.h"

class ListGraph : public Graph {
    int v;
    std::vector<std::vector<std::pair<int, int>>> *list;
    bool directed;
public:
    ListGraph(int v, bool directed);

    ~ListGraph();

    void addEdge(int v1, int v2, int weight) override;

    std::string toString() override;

    int getWeight(int v1, int v2) override;

    bool isDirected() override;

    int getV() override;

    std::vector<std::pair<int, int>> getNeighbours(int v) override;

    std::vector<Edge> getEdges() override;


};


#endif //SDIZO_PROJ_2_LISTGRAPH_H
