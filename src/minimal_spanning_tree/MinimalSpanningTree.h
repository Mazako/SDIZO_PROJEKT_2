#ifndef SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
#define SDIZO_PROJ_2_MINIMALSPANNINGTREE_H

#include <map>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"
#include "minimal_spanning_tree/disjoint_node/DisjointNode.h"

class MinimalSpanningTree {
    static DisjointNode *makeSet(int key);

    static void unionSet(DisjointNode* n1, DisjointNode* n2);

    static void link(DisjointNode* n1, DisjointNode* n2);

    static DisjointNode *findSet(DisjointNode* node);
public:
    static void kruskal(ListGraph* listGraph);

};


#endif //SDIZO_PROJ_2_MINIMALSPANNINGTREE_H
