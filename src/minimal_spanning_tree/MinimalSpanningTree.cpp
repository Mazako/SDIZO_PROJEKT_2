#include "MinimalSpanningTree.h"

DisjointNode *MinimalSpanningTree::makeSet(int key) {
        auto *node = new DisjointNode(key);
        node->setParent(node);
        node->setRank(0);
        return node;
}

DisjointNode *MinimalSpanningTree::findSet(DisjointNode *node) {
    if (node->getParent() != node) {
        node->setParent(findSet(node->getParent()));
    }
    return node->getParent();
}

void MinimalSpanningTree::unionSet(DisjointNode *n1, DisjointNode *n2) {
    link(findSet(n1), findSet(n2));
}

void MinimalSpanningTree::link(DisjointNode *n1, DisjointNode *n2) {
    if (n1->getRank() > n2->getRank()) {
        n2->setParent(n1);
    } else {
        n1->setParent(n2);
        if (n1->getRank() == n2->getRank()) {
            n2->setRank(n2->getRank() + 1);
        }
    }
}

void MinimalSpanningTree::kruskal(ListGraph *listGraph) {
    if (listGraph->isDirected()) {
        throw std::invalid_argument("Graph is directed");
    }
    std::map<int, DisjointNode*> disjointSet;
    for (int i = 0; i < listGraph->getV(); i++) {
        disjointSet[i] = makeSet(i);
    }
}
