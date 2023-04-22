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

std::vector<Edge> MinimalSpanningTree::kruskal(ListGraph *graph) {
    if (graph->isDirected()) {
        throw std::invalid_argument("Graph is directed");
    }
    return performKruskal(graph->getEdges(), graph->getV());

}

std::vector<Edge> MinimalSpanningTree::kruskal(MatrixGraph *graph) {
    if (graph->isDirected()) {
        throw std::invalid_argument("Graph is directed");
    }
    return performKruskal(graph->getEdges(), graph->getV());
}

std::vector<Edge> MinimalSpanningTree::performKruskal(std::vector<Edge> edges, int v) {
    std::vector<Edge> mst;
    std::map<int, DisjointNode*> disjointSet;
    for (int i = 0; i < v; i++) {
        disjointSet[i] = makeSet(i);
    }
    std::sort(edges.begin(), edges.end());
    for (const Edge &edge : edges) {
        auto &v1 = disjointSet[edge.getV1()];
        auto &v2 = disjointSet[edge.getV2()];
        if (findSet(v1) != findSet(v2)) {
            unionSet(v1, v2);
            mst.push_back(edge);
        }
    }
    std::sort(mst.begin(), mst.end(), compareEdgesByVertices);
    return mst;
}

bool MinimalSpanningTree::compareEdgesByVertices(const Edge &e1, const Edge &e2) {
    if (e1.getV1() == e2.getV1()) {
        return e1.getV2() < e2.getV2();
    }
    return e1.getV1() < e2.getV1();
}

std::vector<Edge> MinimalSpanningTree::prim(ListGraph *graph) {
    auto keyComparator = [](const std::pair<int, int> &v1, const std::pair<int, int> &v2) {
        return v1.second > v2.second;
    };
    int* parent = new int [graph->getV()];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, decltype(keyComparator)> queue(keyComparator);


}

