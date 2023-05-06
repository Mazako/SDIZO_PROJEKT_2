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
    (*list)[v1].emplace_back(v2, weight);
    if (!directed) {
        (*list)[v2].emplace_back(v1, weight);
    }
}

std::string ListGraph::toString() {
    using std::string;
    string graph = "";
    for (int i = 0; i < v; i++) {
        graph += std::to_string(i) + " -> { ";
        for (const auto &edge: (*list)[i]) {
            graph += std::to_string(edge.first) + "(" + std::to_string(edge.second) + ") ";
        }
        graph += "}\n";
    }
    return graph;
}

int ListGraph::getWeight(int v1, int v2) {
    auto neighbours = (*list)[v1];
    for (auto &n: neighbours) {
        if (v2 == n.first) {
            return n.second;
        }
    }
    throw;
}

bool ListGraph::isDirected() {
    return directed;
}

int ListGraph::getV() {
    return v;
}

std::vector<Edge> ListGraph::getEdges() {
    std::vector<Edge> edges;
    for (int i = 0; i < v; i++) {
        for (const auto &edge: (*list)[i]) {
            int v2 = edge.first;
            int weight = edge.second;
            edges.push_back(Edge(i, v2, weight));
        }
    }
    return edges;
}

std::vector<std::pair<int, int>> ListGraph::getNeighbours(int v) {
    return (*list)[v];
}