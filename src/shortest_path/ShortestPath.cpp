#include "ShortestPath.h"

void ShortestPath::relax(Graph *g, int v1, int v2, std::vector<int> &distances, std::vector<int> &parents) {
    int possibleNewDistance = distances[v1] + g->getWeight(v1, v2);
    if (distances[v2] > possibleNewDistance) {
        distances[v2] = possibleNewDistance;
        parents[v2] = v1;
    }
}

std::pair<std::vector<int>, std::vector<int>> ShortestPath::initializeGraph(Graph *g, int startingVertex) {
    std::pair<std::vector<int>, std::vector<int>> parentsAndDistances;
    for (int i = 0; i < g->getV(); i++) {
        parentsAndDistances.first.emplace_back(-1);
        if (i == startingVertex) {
            parentsAndDistances.second.emplace_back(0);
        } else {
            parentsAndDistances.second.emplace_back(INT32_MAX);
        }
    }
    return parentsAndDistances;
}

std::pair<std::vector<int>, std::vector<int>> ShortestPath::bellmanFord(Graph *g, int startingVertex) {
    if (!g->isDirected()) {
        throw std::invalid_argument("Graph is not directed");
    }
    auto vectors = initializeGraph(g, startingVertex);
    std::vector<int> &parents = vectors.first;
    std::vector<int> &distances = vectors.second;
    std::vector<Edge> edges = g->getEdges();
    for (int i = 1; i <= g->getV(); i++) {
        for (auto &edge : edges) {
            relax(g, edge.getV1(), edge.getV2(), distances, parents);
        }
    }
    for (auto &edge : edges) {
        if (distances[edge.getV2()] > distances[edge.getV1()] + edge.getWeight()) {
            throw std::invalid_argument("Graph has negative weighted cycles");
        }
    }
    return vectors;


}
