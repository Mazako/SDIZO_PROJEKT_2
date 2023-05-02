#include <iostream>
#include <vector>
#include "graph/matrix/MatrixGraph.h"
#include "graph/list/ListGraph.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"
#include "shortest_path/ShortestPath.h"
#include "minimal_spanning_tree/client/MstClient.h"

void printMenu();

void mstClient();

void shortestPathClient();

int main() {
    using namespace std;
    bool program = true;
    string option;
    while (program) {
        printMenu();
        getline(cin, option);
        if (option == "1") {
            mstClient();
        } else if (option == "2") {
            shortestPathClient();
        } else if (option == "3") {
            program = false;
        } else {
            cout << "Nie ma takiej opcji." << endl;
        }
    }

}

void printMenu() {
    using namespace std;
    cout << "Projekt ze SDIZO #2" << endl;
    cout << "1) Minimalne drzewa rozpinające" << endl;
    cout << "2) Najkrotsza sciezka" << endl;
    cout << "3) wyjdz" << endl;
    cout << "Wybierz opcje: ";
}

void mstClient() {
    auto *client = new MstClient();
    client->start();
    delete client;
}

void shortestPathClient() {

}
