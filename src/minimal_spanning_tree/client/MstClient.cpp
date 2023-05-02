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
            performPrim();
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
        string matrixString = matrix->toString();
        string listString = list->toString();
        stringstream matrixStream(matrixString);
        stringstream listStream(listString);
        string matrixLine, listLine;
        for (int i = 0; i < matrix->getV(); i++) {
            getline(matrixStream, matrixLine, '\n');
            getline(listStream, listLine, '\n');
            cout << matrixLine << "\t\t\t\t" << listLine << endl;
        }

    }
    cout << "1) Algorytm Kruskala" << endl;
    cout << "2) Algorytm Prima" << endl;
    cout << "3) Wczytaj graf z pliku" << endl;
    cout << "4) Wyjdz" << endl;
}

void MstClient::performKruskal() {
    if (matrix == nullptr && list == nullptr) {
        std::cout << "Nie wczytano grafu." << std::endl;
        return;
    }
    std::vector<Edge> m = MinimalSpanningTree::kruskal(matrix);
    std::vector<Edge> l = MinimalSpanningTree::kruskal(list);
    printMstResults(m, l);
}

void MstClient::printMstResults(std::vector<Edge> matrixEdges, std::vector<Edge> listEdges) {
    using namespace std;
    std::sort(matrixEdges.begin(), matrixEdges.end(), MinimalSpanningTree::compareEdgesByVertices);
    std::sort(listEdges.begin(), listEdges.end(), MinimalSpanningTree::compareEdgesByVertices);
    cout << "Macierz \t\t Lista" << endl;
    int totalMatrix = 0;
    int totalList = 0;
    for (int i = 0; i < matrixEdges.size(); i++) {
        cout << matrixEdges[i].toString() << "\t||\t" << listEdges[i].toString() << endl;
        totalMatrix += matrixEdges[i].getWeight();
        totalList += listEdges[i].getWeight();
    }
    cout << "suma: " << totalMatrix << "\t\t" << totalList << endl;
    cout << "Wcisnij dowolny przycisk aby kontynuowac" << endl;
    getchar();
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
        this->startingVertex = get<2>(tup);

    } catch (const exception &e) {
        cerr << "Cos poszlo nie tak z wczytywaniem pliku" << endl;
    }
}

void MstClient::performPrim() {
    if (matrix == nullptr && list == nullptr) {
        std::cout << "Nie wczytano grafu." << std::endl;
        return;
    }
    std::vector<Edge> m = MinimalSpanningTree::prim(matrix, startingVertex);
    std::vector<Edge> l = MinimalSpanningTree::prim(list, startingVertex);
    printMstResults(m, l);
}
