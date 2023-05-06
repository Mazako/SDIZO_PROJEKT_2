#ifndef SDIZO_PROJ_2_SHORTESTPATH_H
#define SDIZO_PROJ_2_SHORTESTPATH_H

#include <vector>
#include <queue>
#include <algorithm>
#include "shortest_path/shortest_path_dto/ShortestPathDTO.h"
#include "graph/Graph.h"
#include "shortest_path/djikstra_vertex/DjikstraVertex.h"

class ShortestPath {
private:
    static std::pair<std::vector<int>, std::vector<int>> initializeGraph(Graph *g, int startingVertex);

    static bool relax(Graph *g, int v1, int v2, std::vector<int> &distances, std::vector<int> &parents);

    static std::vector<int> calculateShortestPath(int i, std::vector<int> &vector);
public:

    static std::vector<ShortestPathDTO> bellmanFord(Graph *g, int startingVertex);

    static std::vector<ShortestPathDTO> djikstra(Graph *g, int startingVertex);


};


#endif //SDIZO_PROJ_2_SHORTESTPATH_H
