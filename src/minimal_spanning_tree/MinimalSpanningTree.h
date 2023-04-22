#ifndef SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
#define SDIZO_PROJ_2_MINIMALSPANNINGTREE_H

#include <map>
#include <algorithm>
#include <queue>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "minimal_spanning_tree/disjoint_node/DisjointNode.h"

class MinimalSpanningTree {
    static DisjointNode *makeSet(int key);

    static void unionSet(DisjointNode *n1, DisjointNode *n2);

    static void link(DisjointNode *n1, DisjointNode *n2);

    static std::vector<Edge> performKruskal(std::vector<Edge> edges, int v);

    static DisjointNode *findSet(DisjointNode *node);

    static bool compareEdgesByVertices(const Edge &e1, const Edge &e2);

public:

    static std::vector<Edge> kruskal(ListGraph *graph);

    static std::vector<Edge> kruskal(MatrixGraph *graph);

    static std::vector<Edge> prim(ListGraph* graph);
};


#endif //SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
