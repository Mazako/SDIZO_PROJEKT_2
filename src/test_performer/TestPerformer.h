#ifndef SDIZO_PROJ_2_TESTPERFORMER_H
#define SDIZO_PROJ_2_TESTPERFORMER_H
#include <vector>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class TestPerformer {
    const std::vector<int> DENSITIES{25, 50, 75, 99};
    const std::vector<int> VERTICES{25, 50, 100, 200, 500};
public:
    static int getRandInt(int start, int end);

    static std::pair<MatrixGraph *, ListGraph *> generateRandomGraphs(int vertices, int density, bool directed);

    static std::string djikstraTest();

    static std::string bellmanFordTest();

};


#endif //SDIZO_PROJ_2_TESTPERFORMER_H
