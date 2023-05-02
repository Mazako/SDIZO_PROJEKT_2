#include "ShortestPathClient.h"

ShortestPathClient::~ShortestPathClient() {
    delete this->matrix;
    delete this->list;
}

void ShortestPathClient::start() {
    using namespace std;
    bool client = true;
    string option;
    while (client) {
        printMenuItems();
        getline(cin, option);
        if (option == "1") {
            performDjikstra();
        } else if (option == "2") {
            performBellmanFord();
        } else if (option == "3") {
            readGraph();
        } else if (option == "4") {
            client = false;
        } else {
            cout << "Nie ma takiej opcji." << endl;
        }
    }
}

void ShortestPathClient::printMenuItems() {
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
    cout << "1) Algorytm Djikstry" << endl;
    cout << "2) Algorytm Bellmana-Forda" << endl;
    cout << "3) Wczytaj graf z pliku" << endl;
    cout << "4) Wyjdz" << endl;

}

void ShortestPathClient::readGraph() {
    using namespace std;
    string fileName;
    cout << "Podaj nazwe pliku" << endl;
    getline(cin, fileName);
    try {
        std::tuple<Graph *, Graph *, int> tup = Graph::readGraphFromFile(fileName, true);
        this->matrix = dynamic_cast<MatrixGraph *>(get<1>(tup));
        this->list = dynamic_cast<ListGraph *>(get<0>(tup));
        this->startingVertex = get<2>(tup);

    } catch (const exception &e) {
        cerr << "Cos poszlo nie tak z wczytywaniem pliku" << endl;
    }

}

void ShortestPathClient::performBellmanFord() {
    using namespace std;
    if (matrix == nullptr && list == nullptr) {
        cerr << "Nie wczytano grafu." << endl;
        return;
    }
    std::vector<ShortestPathDTO> m = ShortestPath::bellmanFord(matrix, startingVertex);
    std::vector<ShortestPathDTO> l = ShortestPath::bellmanFord(list, startingVertex);
    printShortestPathResults(m, l);
    cout << " Nacisnij dowolny przycisk aby kontynuowac" << endl;
    getchar();
}

void ShortestPathClient::performDjikstra() {
    using namespace std;
    if (matrix == nullptr && list == nullptr) {
        cerr << "Nie wczytano grafu." << endl;
        return;
    }
    std::vector<ShortestPathDTO> m = ShortestPath::djikstra(matrix, startingVertex);
    std::vector<ShortestPathDTO> l = ShortestPath::djikstra(list, startingVertex);
    printShortestPathResults(m, l);
    cout << " Nacisnij dowolny przycisk aby kontynuowac" << endl;
    getchar();
}


void ShortestPathClient::printShortestPathResults(std::vector<ShortestPathDTO> matrixEdges,
                                                  std::vector<ShortestPathDTO> listEdges) {
    using namespace std;
    sort(matrixEdges.begin(), matrixEdges.end(), [](ShortestPathDTO &a, ShortestPathDTO &b) {
        return a.getStart() > b.getStart();
    });

    sort(listEdges.begin(), listEdges.end(), [](ShortestPathDTO &a, ShortestPathDTO &b) {
        return a.getStart() > b.getStart();
    });
    cout << "Start: " << to_string(startingVertex) << endl;
    cout << "Macierz" << setw(matrix->getV() + 40) << "Lista" << endl;
    cout << "End  Dist  Path" << endl;
    for (int i = 0; i < matrixEdges.size(); i++) {
        cout << matrixEdges[i].toString() << setw(matrix->getV() + 40) << listEdges[i].toString() << endl;
    }
}
