#include <iostream>
#include "graph/matrix/MatrixGraph.h"
#include "graph/list/ListGraph.h"

int main() {
    using namespace std;
    cout << "Projekt 2" << endl;
    auto* g = new MatrixGraph(5, true);
    g->addEdge(3, 2, 5);
    cout << g->toString() << endl;
    cout << g->getWeight(3, 2) << endl;
    return 0;
}