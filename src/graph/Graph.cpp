#include "Graph.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

std::tuple<Graph *, Graph *, int> Graph::readGraphFromFile(std::string &filename, bool directed) {
    using namespace std;
    string line;
    fstream newFile;
    newFile.open(filename, ios::in);
    getline(newFile, line);
    if (line.empty()) {
        throw std::invalid_argument("Bad file format");
    }
    stringstream stream(line);
    int edges, vertices, startingVertex;
    stream >> edges;
    stream >> vertices;
    stream >> startingVertex;
    Graph *list = new ListGraph(vertices, directed);
    Graph *matrix = new MatrixGraph(vertices, directed);
    for (int i = 0; i < edges; i++) {
        getline(newFile, line);
        stringstream edgeStream(line);
        int v1, v2, weight;
        edgeStream >> v1;
        edgeStream >> v2;
        if (v1 >= vertices || v2 >= vertices) {
            throw std::invalid_argument("Bad file format");
        }
        edgeStream >> weight;
        list->addEdge(v1, v2, weight);
        matrix->addEdge(v1, v2, weight);
    }
    return std::tuple<Graph *, Graph *, int>{list, matrix, startingVertex};

}
