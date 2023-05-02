#ifndef SDIZO_PROJ_2_MSTCLIENT_H
#define SDIZO_PROJ_2_MSTCLIENT_H


#include "graph/Graph.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class MstClient {
    ListGraph *list;
    MatrixGraph *matrix;
    int selectedElement;

    void printMenuItems();

    void performKruskal();

    void performPrim();

    static void printMstResults(std::vector<Edge> matrixEdges, std::vector<Edge> listEdges);


public:
    ~MstClient();

    void start();

    void readGraph();
};


#endif //SDIZO_PROJ_2_MSTCLIENT_H
