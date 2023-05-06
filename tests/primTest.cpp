#include "gtest/gtest.h"
#include "graph/Graph.h"
#include "minimal_spanning_tree/MinimalSpanningTree.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class PrimTest : public ::testing::Test {
public:
    static int getTotal(std::vector<Edge> &vector) {
        int total = 0;
        for (const auto &item: vector) {
            total += item.getWeight();
        }
        return total;
    }
};

TEST_F(PrimTest, Test1) {
    std::string filename = "resources/mst_basic_1";
    auto g = Graph::readGraphFromFile(filename, false);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto list = MinimalSpanningTree::prim(listGraph, startingVertex);
    auto matrix =  MinimalSpanningTree::prim(matrixGraph, startingVertex);
    ASSERT_EQ(PrimTest::getTotal(list), 16);
    ASSERT_EQ(PrimTest::getTotal(matrix), 16);
}

TEST_F(PrimTest, Test2) {
    std::string filename = "resources/mst_basic_2";
    auto g = Graph::readGraphFromFile(filename, false);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto list = MinimalSpanningTree::prim(listGraph, startingVertex);
    auto matrix =  MinimalSpanningTree::prim(matrixGraph, startingVertex);
    ASSERT_EQ(PrimTest::getTotal(list), 16);
    ASSERT_EQ(PrimTest::getTotal(matrix), 16);
}
TEST_F(PrimTest, Test3) {
    std::string filename = "resources/mst_basic_3";
    auto g = Graph::readGraphFromFile(filename, false);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto list = MinimalSpanningTree::prim(listGraph, startingVertex);
    auto matrix =  MinimalSpanningTree::prim(matrixGraph, startingVertex);
    ASSERT_EQ(PrimTest::getTotal(list), 6);
    ASSERT_EQ(PrimTest::getTotal(matrix), 6);
}


