#include "MstClient.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"

MstClient::~MstClient() {
    delete this->matrix;
    delete this->list;
}

void MstClient::start() {
    using namespace std;
    bool client = true;
    string option;
    while (client) {
        printMenuItems();
        getline(cin, option);
        if (option == "1") {
            performKruskal();
        } else if (option == "2") {
        } else if (option == "3") {
            readGraph();
        } else if (option == "4") {
            client = false;
        } else {
            cout << "Nie ma takiej opcji." << endl;
        }
    }

}

void MstClient::printMenuItems() {
    using namespace std;
    if (matrix == nullptr && list == nullptr) {
        cout << "Nie wczytano grafu." << endl;
    } else {
        cout << "Macierz sasiedztwa" << endl;
        cout << matrix->toString() << endl;
        cout << endl;
        cout << endl;
        cout << "Lista sasiedztwa" << endl;
        cout << list->toString() << endl;
        cout << endl;
        cout << endl;
    }
    cout << "1) Algorytm Kruskala" << endl;
    cout << "2) Algorytm Prima" << endl;
    cout << "3) Wczytaj graf z pliku" << endl;
    cout << "4) Wyjdz" << endl;
}

void MstClient::performKruskal() {
    std::vector<Edge> m = MinimalSpanningTree::kruskal(matrix);
    std::vector<Edge> l = MinimalSpanningTree::kruskal(list);
    printMstResults(m, l);
}

void MstClient::printMstResults(std::vector<Edge> matrixEdges, std::vector<Edge> listEdges) {
    using namespace std;
    std::sort(matrixEdges.begin(), matrixEdges.end(), MinimalSpanningTree::compareEdgesByVertices);
    std::sort(listEdges.begin(), listEdges.end(), MinimalSpanningTree::compareEdgesByVertices);
    for (int i = 0; i < matrixEdges.size(); i++) {
        cout << matrixEdges[i].toString() << "\t||\t" << listEdges[i].toString() << endl;
    }
}

void MstClient::readGraph() {
    using namespace std;
    string fileName;
    cout << "Podaj nazwe pliku" << endl;
    getline(cin, fileName);
    try {
        std::tuple<Graph *, Graph *, int> tup = Graph::readGraphFromFile(fileName, false);
        this->matrix = dynamic_cast<MatrixGraph *>(get<1>(tup));
        this->list = dynamic_cast<ListGraph *>(get<0>(tup));

    } catch (const exception &e) {
        cerr << "Cos poszlo nie tak z wczytywaniem pliku" << endl;
    }
}
