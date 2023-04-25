#include "MatrixGraph.h"
MatrixGraph::MatrixGraph(int v, bool directed) {
    this->v = v;
    this->directed = directed;
    this->array = new int* [v];
    for (int i = 0; i < v; i++) {
        this->array[i] = new int [v];
        for (int j = 0; j < v; j++) {
            this->array[i][j] = INT32_MAX;
        }
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < v; i++) {
        delete[] this->array[i];
    }
    delete [] this->array;
}

void MatrixGraph::addEdge(int v1, int v2, int weight) {
    if (v1 >= v || v2 >= v) {
        throw std::invalid_argument("Too big vertex id");
    }
    this->array[v1][v2] = weight;
    if (!directed) {
        this->array[v2][v1] = weight;
    }
}

std::string MatrixGraph::toString() {
    using std::to_string;
    using std::string;

    string total = "";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            string value = array[i][j] == INT32_MAX ? "inf" : to_string(array[i][j]);
            total += value + "\t";
        }
        total += "\n";
    }
    return total;
}

bool MatrixGraph::isDirected() {
    return this->directed;
}

int MatrixGraph::getWeight(int v1, int v2) {
    return array[v1][v2];
}

int MatrixGraph::getV()  {
    return this->v;
}

std::vector<Edge> MatrixGraph::getEdges() {
    std::vector<Edge> edges;
    for (int i = 0; i < v; i++) {
        for (int j = directed ? 0 : i; j < v; j++) {
            if (array[i][j] != INT32_MAX) {
                edges.emplace_back(i, j, array[i][j]);
            }
        }
    }
    return edges;
}

std::vector<std::pair<int, int>> MatrixGraph::getNeighbours(int v) {
    std::vector<std::pair<int, int>> neighbours;
    for (int i = 0; i < this->v; i++) {
        if (array[v][i] != INT32_MAX) {
            neighbours.emplace_back(i, array[v][i]);
        }
    }
    return neighbours;
}
