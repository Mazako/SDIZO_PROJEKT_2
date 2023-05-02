#include "ShortestPath.h"

bool ShortestPath::relax(Graph *g, int v1, int v2, std::vector<int> &distances, std::vector<int> &parents) {
    int possibleNewDistance;
    if (distances[v1] == INT32_MAX) {
        possibleNewDistance = INT32_MAX;
    } else {
        possibleNewDistance = distances[v1] + g->getWeight(v1, v2);
    }
    if (distances[v2] > possibleNewDistance) {
        distances[v2] = possibleNewDistance;
        parents[v2] = v1;
        return true;
    }
    return false;
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
        for (auto &edge: edges) {
            relax(g, edge.getV1(), edge.getV2(), distances, parents);
        }
    }
    for (auto &edge: edges) {
        if (distances[edge.getV2()] > distances[edge.getV1()] + edge.getWeight()) {
            throw std::invalid_argument("Graph has negative weighted cycles");
        }
    }
    return vectors;
}

std::vector<ShortestPathDTO> ShortestPath::djikstra(Graph *g, int startingVertex) {
    auto comparator = [](DjikstraVertex &v1, DjikstraVertex &v2) {
        return v1.getDistance() < v2.getDistance();
    };
    if (!g->isDirected()) {
        throw std::invalid_argument("Graph is not directed");
    }
    auto vectors = initializeGraph(g, startingVertex);
    std::vector<int> &parents = vectors.first;
    std::vector<int> &distances = vectors.second;
    std::vector<DjikstraVertex> vertices;
    vertices.reserve(g->getV());
    for (int i = 0; i < g->getV(); i++) {
        vertices.emplace_back(i, distances[i]);
    }
    while (!vertices.empty()) {
        auto u = std::min_element(vertices.begin(), vertices.end(), comparator);
        for (auto &neighbour: g->getNeighbours(u->getV())) {
            bool isRelaxed = relax(g, u->getV(), neighbour.first, distances, parents);
            if (isRelaxed) {
                auto djikstraVertex = std::find_if(vertices.begin(), vertices.end(), [&neighbour](DjikstraVertex &v) {
                    return v.getV() == neighbour.first;
                });
                djikstraVertex->setDistance(u->getDistance() + neighbour.second);
            }
        }
        vertices.erase(u);
    }
    std::vector<ShortestPathDTO> result;
    for (int i = 0; i < g->getV(); i++) {
        if (parents[i] != -1) {
            result.emplace_back(startingVertex, i, distances[i], calculateShortestPath(i, parents));
        }
    }
    std::sort(result.begin(), result.end(), [](ShortestPathDTO &v1, ShortestPathDTO &v2) {
        return v1.getAnEnd() > v2.getAnEnd();
    });

    return result;

}

std::vector<int> ShortestPath::calculateShortestPath(int i, std::vector<int> &parents) {
    std::vector<int> shortestPath;
    while (i != -1) {
        shortestPath.emplace_back(i);
        i = parents[i];
    }
    return shortestPath;
}
