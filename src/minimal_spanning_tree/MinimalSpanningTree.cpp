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

std::vector<Edge> MinimalSpanningTree::kruskal(Graph *graph) {
    if (graph->isDirected()) {
        throw std::invalid_argument("Graph is directed");
    }
    return performKruskal(graph->getEdges(), graph->getV());

}

std::vector<Edge> MinimalSpanningTree::performKruskal(std::vector<Edge> edges, int v) {
    std::vector<Edge> mst;
    std::map<int, DisjointNode *> disjointSet;
    for (int i = 0; i < v; i++) {
        disjointSet[i] = makeSet(i);
    }
    std::sort(edges.begin(), edges.end());
    for (const Edge &edge: edges) {
        auto &v1 = disjointSet[edge.getV1()];
        auto &v2 = disjointSet[edge.getV2()];
        if (findSet(v1) != findSet(v2)) {
            unionSet(v1, v2);
            mst.push_back(edge);
        }
    }
    return mst;
}

bool MinimalSpanningTree::compareEdgesByVertices(const Edge &e1, const Edge &e2) {
    if (e1.getV1() == e2.getV1()) {
        return e1.getV2() < e2.getV2();
    }
    return e1.getV1() < e2.getV1();
}

std::vector<Edge> MinimalSpanningTree::prim(Graph *graph, int startingVertex) {
    std::vector<int> parents(graph->getV());
    std::vector<PrimVertex> keySet;
    std::vector<bool> visited(graph->getV());
    for (int i = 0; i < graph->getV(); i++) {
        parents[i] = -1;
        visited[i] = false;
        if (i == startingVertex) {
            keySet.emplace_back(i, 0);
        } else {
            keySet.emplace_back(i, INT32_MAX);
        }
    }
    std::vector<Edge> mst;
    while (!keySet.empty()) {
        auto minElement = std::min_element(keySet.begin(), keySet.end(), [](PrimVertex &a, PrimVertex &b) {
            return a.getKey() < b.getKey();
        });
        for (auto &neighbour: graph->getNeighbours(minElement->getV())) {
            auto neighbourKey = std::find_if(keySet.begin(), keySet.end(), [&neighbour](PrimVertex &a) {
                return a.getV() == neighbour.first;
            });
            if (neighbourKey->getV() != minElement->getV() && neighbourKey != keySet.end() &&
                neighbour.second < neighbourKey->getKey()) {
                parents[neighbour.first] = minElement->getV();
                neighbourKey->setKey(neighbour.second);
            }
        }
        keySet.erase(minElement);
    }
    for (int i = 0; i < graph->getV(); i++) {
        if (parents[i] != -1) {
            mst.emplace_back(parents[i], i, graph->getWeight(parents[i], i));
        }
    }
    return mst;
}
