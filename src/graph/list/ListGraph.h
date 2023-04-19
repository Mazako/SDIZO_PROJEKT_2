#ifndef SDIZO_PROJ_2_LISTGRAPH_H
#define SDIZO_PROJ_2_LISTGRAPH_H
#include <string>
#include <vector>

class ListGraph {
    int v;
    std::vector<std::vector<std::pair<int, int>>>* list;
    bool directed;
public:
    ListGraph(int v, bool directed);

    ~ListGraph();

    void addEdge(int v1, int v2, int weight = 1);

    std::string toString();

    int getWeight(int v1, int v2);

    bool isDirected() const;

    int getV() const;

};


#endif //SDIZO_PROJ_2_LISTGRAPH_H
