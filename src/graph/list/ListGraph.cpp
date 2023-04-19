#include "ListGraph.h"

ListGraph::ListGraph(int v, bool directed) {
    this->v = v;
    this->directed = directed;
    list = new std::vector<std::vector<std::pair<int, int>>>(v);
}

ListGraph::~ListGraph() {
    delete list;
}

void ListGraph::addEdge(int v1, int v2, int weight) {
    (*list)[v1].push_back(std::make_pair(v2, weight));
    if (!directed) {
        (*list)[v2].push_back(std::make_pair(v1, weight));
    }
}

std::string ListGraph::toString() {
    using std::string;
    string graph = "";
    for (int i = 0; i < v; i++) {
        graph += std::to_string(i) + " -> { ";
        for (const auto &edge : (*list)[i]) {
            graph += std::to_string(edge.first) + "(" + std::to_string(edge.second) + ") ";
        }
        graph += "}\n";
    }
    return graph;
}

int ListGraph::getWeight(int v1, int v2) {
    return (*list)[v1][v2].second;
}

bool ListGraph::isDirected() const {
    return directed;
}

int ListGraph::getV() const {
    return v;
}
