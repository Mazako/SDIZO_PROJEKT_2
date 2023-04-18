#include "MatrixGraph.h"
MatrixGraph::MatrixGraph(int v) {
    this->v = v;
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
    this->array[v1][v2] = weight;
    this->array[v2][v1] = weight;
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
