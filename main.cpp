#include <iostream>
#include "graph/matrix/MatrixGraph.h"

int main() {
    using namespace std;
    cout << "Projekt 2" << endl;
    auto* g = new MatrixGraph(5, true);
    g->addEdge(0, 1, 4);
    cout << g->toString() << endl;
    return 0;
}