#include <random>
#include <algorithm>
#include "TestPerformer.h"

std::pair<MatrixGraph *, ListGraph *> TestPerformer::generateRandomGraphs(int vertices, int density, bool directed) {
    ListGraph* listGraph = new ListGraph(vertices, directed);
    MatrixGraph* matrixGraph = new MatrixGraph(vertices, directed);
    int maxEdges;
    std::vector<std::pair<int, int>> visitedVertices;
    if (directed) {
        maxEdges = (vertices * (vertices - 1)) / 2;
    } else {
        maxEdges = vertices * (vertices - 1);
    }
    int correctEdges = maxEdges * (density / 100.);
    int i = 0;
    while (i < correctEdges) {
        int v1 = getRandInt(0, vertices - 1);
        int v2 = getRandInt(0, vertices - 1);
        auto find = std::find_if(visitedVertices.begin(), visitedVertices.end(), [&directed, &v1, &v2](std::pair<int, int> &a) {
            if (!directed) {
                return a.first == v1 && a.second == v2;
            } else {
                return (a.first == v1 && a.second == v2) || (a.first == v2 && a.second == v1);
            }
        });
        if (find != visitedVertices.end()) {
            continue;
        }
        int weight = getRandInt(0, INT32_MAX - 1);
        listGraph->addEdge(v1, v2, weight);
        matrixGraph->addEdge(v1, v2, weight);
        visitedVertices.emplace_back(v1, v2);
        i++;
    }
    return std::pair<MatrixGraph *, ListGraph *>{matrixGraph, listGraph};
}

int TestPerformer::getRandInt(int start, int end) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<> distribution(start, end);
    return distribution(rng);
}

std::string TestPerformer::djikstraTest() {
    return std::string();
}
