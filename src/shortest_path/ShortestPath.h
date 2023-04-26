#ifndef SDIZO_PROJ_2_SHORTESTPATH_H
#define SDIZO_PROJ_2_SHORTESTPATH_H
#include <vector>
#include "shortest_path/shortest_path_dto/ShortestPathDTO.h"
#include "graph/Graph.h"

class ShortestPath {
    static std::pair<std::vector<int>, std::vector<int>> initializeGraph(Graph* g, int startingVertex);

    static void relax(Graph* g, int v1, int v2, std::vector<int> &distances, std::vector<int> &parents);
public:
    static std::pair<std::vector<int>, std::vector<int>> bellmanFord(Graph *g, int startingVertex);

    static std::vector<ShortestPathDTO> &djikstra(Graph* g, int startingVertex);
};


#endif //SDIZO_PROJ_2_SHORTESTPATH_H
