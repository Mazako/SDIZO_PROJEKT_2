#ifndef SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
#define SDIZO_PROJ_2_MINIMALSPANNINGTREE_H

#include <map>
#include <algorithm>
#include <queue>
#include <fstream>
#include <sstream>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "minimal_spanning_tree/disjoint_node/DisjointNode.h"
#include "minimal_spanning_tree/prim_vertex/PrimVertex.h"

class MinimalSpanningTree {
    static DisjointNode *makeSet(int key);

    static void unionSet(DisjointNode *n1, DisjointNode *n2);

    static void link(DisjointNode *n1, DisjointNode *n2);

    static std::vector<Edge> performKruskal(std::vector<Edge> edges, int v);

    static DisjointNode *findSet(DisjointNode *node);

public:

    static std::vector<Edge> kruskal(Graph *graph);

    static bool compareEdgesByVertices(const Edge &e1, const Edge &e2);

    static std::vector<Edge> prim(Graph *graph, int startingVertex);
};


#endif //SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
