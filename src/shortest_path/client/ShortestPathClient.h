#ifndef SDIZO_PROJ_2_SHORTESTPATHCLIENT_H
#define SDIZO_PROJ_2_SHORTESTPATHCLIENT_H

#include <iomanip>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "shortest_path/shortest_path_dto/ShortestPathDTO.h"
#include "shortest_path/ShortestPath.h"

class ShortestPathClient {
    ListGraph *list;
    MatrixGraph *matrix;
    int startingVertex;

    void printMenuItems();

    void performDjikstra();

    void performBellmanFord();

    void printShortestPathResults(std::vector<ShortestPathDTO> matrixEdges, std::vector<ShortestPathDTO> listEdges);


public:
    ~ShortestPathClient();

    void start();

    void readGraph();
};


#endif //SDIZO_PROJ_2_SHORTESTPATHCLIENT_H
