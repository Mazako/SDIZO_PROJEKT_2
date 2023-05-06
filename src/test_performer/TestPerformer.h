#ifndef SDIZO_PROJ_2_TESTPERFORMER_H
#define SDIZO_PROJ_2_TESTPERFORMER_H

#include <vector>
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class TestPerformer {
    static inline const std::vector<int> DENSITIES{25, 50, 75, 99};
    static inline const std::vector<int> VERTICES{10, 25 ,50, 75, 100};

    static std::pair<long, long> singleDjikstraTest(int density, int vertices);

    static std::pair<long, long> singleBellmanFordTest(int density, int vertices);

    static std::pair<long, long> singleKruskalTest(int density, int vertices);

    static std::pair<long, long> singlePrimTest(int density, int vertices);

public:
    static int getRandInt(int start, int end);

    static std::pair<MatrixGraph *, ListGraph *> generateRandomGraphs(int vertices, int density, bool directed);

    static void djikstraTest();

    static void bellmanFordTest();

    static void kruskalTest();

    static void primTest();

    static double avg(std::vector<long> &vector);

    static void allTests();
};


#endif //SDIZO_PROJ_2_TESTPERFORMER_H
