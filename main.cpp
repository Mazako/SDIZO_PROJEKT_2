#include <iostream>
#include <vector>
#include "graph/matrix/MatrixGraph.h"
#include "graph/list/ListGraph.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"

int main() {
    using namespace std;
    cout << "Projekt 2" << endl;
    auto* g = new ListGraph(8, false);
    g->addEdge(0, 2, 9);
    g->addEdge(2, 4, 3);
    g->addEdge(2, 1, 5);
    g->addEdge(2, 6, 1);
    g->addEdge(1, 6, 4);
    g->addEdge(1, 5, 2);
    g->addEdge(5, 7, 6);
    g->addEdge(7, 6, 6);
    auto mst = MinimalSpanningTree::kruskal(g);
    for (const auto &e : mst) {
        cout << e.toString() << endl;
    }
}