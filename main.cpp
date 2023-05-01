#include <iostream>
#include <vector>
#include "graph/matrix/MatrixGraph.h"
#include "graph/list/ListGraph.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"
#include "shortest_path/ShortestPath.h"

void mst();

int main() {
    using namespace std;
    cout << "Projekt 2" << endl;
    Graph* g = new MatrixGraph(8, true);
    g->addEdge(0, 2, 9);
    g->addEdge(2, 4, 3);
    g->addEdge(2, 1, 5);
    g->addEdge(2, 6, 1);
    g->addEdge(1, 6, 4);
    g->addEdge(1, 5, 2);
    g->addEdge(5, 7, 6);
    g->addEdge(7, 6, 6);
    cout << g->toString() << endl;
    ShortestPath::djikstra(g, 0);

}

void mst() {
    using namespace std;
    cout << "Projekt 2" << endl;
    Graph* g = new MatrixGraph(8, false);
    g->addEdge(0, 2, 9);
    g->addEdge(2, 4, 3);
    g->addEdge(2, 1, 5);
    g->addEdge(2, 6, 1);
    g->addEdge(1, 6, 4);
    g->addEdge(1, 5, 2);
    g->addEdge(5, 7, 6);
    g->addEdge(7, 6, 6);
    cout << g->toString() << endl;
    cout << "PRIM" << endl;
    int primTotal = 0, kruskalTotal = 0;
    auto mst = MinimalSpanningTree::prim(g, 0);
    for (const auto &e : mst) {
        primTotal += e.getWeight();
        cout << e.toString() << endl;
    }
    cout << "KRUSKAL" << endl;
    auto kruskal = MinimalSpanningTree::kruskal(g);
    for (const auto &e : kruskal) {
        cout << e.toString() << endl;
        kruskalTotal += e.getWeight();
    }
    cout << primTotal << endl;
    cout << kruskalTotal << endl;
}
