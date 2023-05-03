#include <random>
#include <algorithm>
#include <chrono>
#include "TestPerformer.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"
#include "shortest_path/ShortestPath.h"

void TestPerformer::allTests() {
    bellmanFordTest();
    djikstraTest();
    kruskalTest();
    primTest();
}

std::pair<MatrixGraph *, ListGraph *> TestPerformer::generateRandomGraphs(int vertices, int density, bool directed) {
    ListGraph *listGraph = new ListGraph(vertices, directed);
    MatrixGraph *matrixGraph = new MatrixGraph(vertices, directed);
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
        auto find = std::find_if(visitedVertices.begin(), visitedVertices.end(),
                                 [&directed, &v1, &v2](std::pair<int, int> &a) {
                                     if (!directed) {
                                         return a.first == v1 && a.second == v2;
                                     } else {
                                         return (a.first == v1 && a.second == v2) || (a.first == v2 && a.second == v1);
                                     }
                                 });
        if (find != visitedVertices.end()) {
            continue;
        }
        int weight = getRandInt(0, 2000);
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

void TestPerformer::djikstraTest() {
    std::string list;
    std::string matrix;
    for (const int& count : VERTICES) {
        for (const int &density: DENSITIES) {
            std::cout << "Djikstra tests (" <<count << "," << density << "%)"  << std::endl;
            std::pair<long, long> results = TestPerformer::singleDjikstraTest(density, count);
            matrix += std::to_string(results.first);
            list += std::to_string(results.second);
            if (density != 99) {
                matrix += ";";
                list += ";";
            }
        }
        matrix += "\n";
        list += "\n";
    }
    std::cout << "DJIKSTRA (MATRIX)\n" << matrix << std::endl;
    std::cout << "DJIKSTRA(LIST)\n" << list << std::endl;
}

void TestPerformer::bellmanFordTest() {
    std::string list;
    std::string matrix;
    for (const int& count : VERTICES) {
        for (const int &density: DENSITIES) {
            std::cout << "Bellman-Ford tests (" <<count << "," << density << "%)"  << std::endl;
            std::pair<long, long> results = TestPerformer::singleBellmanFordTest(density, count);
            matrix += std::to_string(results.first);
            list += std::to_string(results.second);
            if (density != 99) {
                matrix += ";";
                list += ";";
            }
        }
        matrix += "\n";
        list += "\n";
    }
    std::cout << "BELLMAN-FORD (MATRIX)\n" << matrix << std::endl;
    std::cout << "BELLMAN-FORD (LIST)\n" << list << std::endl;
}

void TestPerformer::kruskalTest() {
    std::string list;
    std::string matrix;
    for (const int& count : VERTICES) {
        for (const int &density: DENSITIES) {
            std::cout << "Kruskal tests (" <<count << "," << density << "%)"  << std::endl;
            std::pair<long, long> results = TestPerformer::singleKruskalTest(density, count);
            matrix += std::to_string(results.first);
            list += std::to_string(results.second);
            if (density != 99) {
                matrix += ";";
                list += ";";
            }
        }
        matrix += "\n";
        list += "\n";
    }
    std::cout << "KRUSKAL (MATRIX)\n" << matrix << std::endl;
    std::cout << "KRUSKAL (LIST)\n" << list << std::endl;
}


void TestPerformer::primTest() {
    std::string list;
    std::string matrix;
    for (const int& count : VERTICES) {
        for (const int &density: DENSITIES) {
            std::cout << "Prim tests (" <<count << "," << density << "%)"  << std::endl;
            std::pair<long, long> results = TestPerformer::singlePrimTest(density, count);
            matrix += std::to_string(results.first);
            list += std::to_string(results.second);
            if (density != 99) {
                matrix += ";";
                list += ";";
            }
        }
        matrix += "\n";
        list += "\n";
    }
    std::cout << "PRIM (MATRIX)\n" << matrix << std::endl;
    std::cout << "PRIM (LIST)\n" << list << std::endl;

}

std::pair<long, long> TestPerformer::singleDjikstraTest(int density, int vertices) {
    using namespace std::chrono;
    std::vector<long> matrixTimes;
    std::vector<long> listTimes;
    for (int i = 0; i < 100; i++) {
        std::pair<MatrixGraph *, ListGraph *> graphs = generateRandomGraphs(vertices, density, true);
        MatrixGraph *matrixGraph = graphs.first;
        ListGraph *listGraph = graphs.second;
        int vertex = getRandInt(0, vertices - 1);
        auto start = high_resolution_clock::now();
        ShortestPath::djikstra(matrixGraph, vertex);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        matrixTimes.emplace_back(duration.count());
        start = high_resolution_clock::now();
        ShortestPath::djikstra(listGraph, vertex);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        listTimes.emplace_back(duration.count());
        delete listGraph;
        delete matrixGraph;
    }
    return std::pair<long, long> {avg(matrixTimes), avg(listTimes)};

}

double TestPerformer::avg(std::vector<long> &vector) {
    double total = 0;
    for (const long &time : vector) {
        total += (double) time;
    }
    return total / (double) vector.size();
}


std::pair<long, long> TestPerformer::singleBellmanFordTest(int density, int vertices) {
    using namespace std::chrono;
    std::vector<long> matrixTimes;
    std::vector<long> listTimes;
    for (int i = 0; i < 100; i++) {
        std::pair<MatrixGraph *, ListGraph *> graphs = generateRandomGraphs(vertices, density, true);
        MatrixGraph *matrixGraph = graphs.first;
        ListGraph *listGraph = graphs.second;
        int vertex = getRandInt(0, vertices - 1);
        auto start = high_resolution_clock::now();
        ShortestPath::bellmanFord(matrixGraph, vertex);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        matrixTimes.emplace_back(duration.count());
        start = high_resolution_clock::now();
        ShortestPath::bellmanFord(listGraph, vertex);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        listTimes.emplace_back(duration.count());
        delete listGraph;
        delete matrixGraph;
    }
    return std::pair<long, long> {avg(matrixTimes), avg(listTimes)};
}

std::pair<long, long> TestPerformer::singleKruskalTest(int density, int vertices) {
    using namespace std::chrono;
    std::vector<long> matrixTimes;
    std::vector<long> listTimes;
    for (int i = 0; i < 100; i++) {
        std::pair<MatrixGraph *, ListGraph *> graphs = generateRandomGraphs(vertices, density, false);
        MatrixGraph *matrixGraph = graphs.first;
        ListGraph *listGraph = graphs.second;
        auto start = high_resolution_clock::now();
        MinimalSpanningTree::kruskal(matrixGraph);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        matrixTimes.emplace_back(duration.count());
        start = high_resolution_clock::now();
        MinimalSpanningTree::kruskal(listGraph);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        listTimes.emplace_back(duration.count());
        delete listGraph;
        delete matrixGraph;
    }
    return std::pair<long, long> {avg(matrixTimes), avg(listTimes)};
}

std::pair<long, long> TestPerformer::singlePrimTest(int density, int vertices) {
    using namespace std::chrono;
    std::vector<long> matrixTimes;
    std::vector<long> listTimes;
    for (int i = 0; i < 100; i++) {
        std::pair<MatrixGraph *, ListGraph *> graphs = generateRandomGraphs(vertices, density, false);
        MatrixGraph *matrixGraph = graphs.first;
        ListGraph *listGraph = graphs.second;
        int vertex = getRandInt(0, vertices - 1);
        auto start = high_resolution_clock::now();
        MinimalSpanningTree::prim(matrixGraph, vertex);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        matrixTimes.emplace_back(duration.count());
        start = high_resolution_clock::now();
        MinimalSpanningTree::prim(listGraph, vertex);
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        listTimes.emplace_back(duration.count());
        delete listGraph;
        delete matrixGraph;
    }
    return std::pair<long, long> {avg(matrixTimes), avg(listTimes)};

}
