#include "gtest/gtest.h"
#include "graph/Graph.h"
#include "shortest_path/ShortestPath.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class PrimTest : public ::testing::Test {

};

TEST_F(PrimTest, BasicBellmanTest1) {
    std::string filename = "resources/shortest_path_basic_1";
    auto g = Graph::readGraphFromFile(filename, true);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto bellmanList = ShortestPath::bellmanFord(listGraph, startingVertex);
    auto bellmanMatrix =  ShortestPath::bellmanFord(matrixGraph, startingVertex);
    ASSERT_EQ(bellmanList, bellmanMatrix);
    ASSERT_EQ(bellmanMatrix[0].getDistance(), 7);
    ASSERT_EQ(bellmanMatrix[1].getDistance(), 9);
    ASSERT_EQ(bellmanMatrix[2].getDistance(), 16);
    ASSERT_EQ(bellmanMatrix[3].getDistance(), 19);
    ASSERT_EQ(bellmanMatrix[4].getDistance(), 17);
    std::vector<int>p0 {1, 0};
    std::vector<int>p1 {2, 1, 0};
    std::vector<int>p2 {3, 1, 0};
    std::vector<int>p3 {4, 2, 1, 0};
    std::vector<int>p4 {5, 3, 1, 0};
    ASSERT_EQ(bellmanMatrix[0].getPath(), p0);
    ASSERT_EQ(bellmanMatrix[1].getPath(), p1);
    ASSERT_EQ(bellmanMatrix[2].getPath(), p2);
    ASSERT_EQ(bellmanMatrix[3].getPath(), p3);
    ASSERT_EQ(bellmanMatrix[4].getPath(), p4);
}

TEST_F(PrimTest, BasicBellmanTest2) {
    std::string filename = "resources/shortest_path_basic_2";
    auto g = Graph::readGraphFromFile(filename, true);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto bellmanList = ShortestPath::bellmanFord(listGraph, startingVertex);
    auto bellmanMatrix =  ShortestPath::bellmanFord(matrixGraph, startingVertex);
    ASSERT_EQ(bellmanList, bellmanMatrix);
    ASSERT_EQ(bellmanMatrix[0].getDistance(), 1);
    ASSERT_EQ(bellmanMatrix[1].getDistance(), 4);
    ASSERT_EQ(bellmanMatrix[2].getDistance(), 3);
    ASSERT_EQ(bellmanMatrix[3].getDistance(), 6);
    ASSERT_EQ(bellmanMatrix[4].getDistance(), 7);
    std::vector<int> p0 {1, 0};
    std::vector<int> p1{2, 0};
    std::vector<int> p2{3, 1, 0};
    std::vector<int> p3{4, 2, 0};
    std::vector<int> p4{5, 4, 2, 0};
    ASSERT_EQ(bellmanMatrix[0].getPath(), p0);
    ASSERT_EQ(bellmanMatrix[1].getPath(), p1);
    ASSERT_EQ(bellmanMatrix[2].getPath(), p2);
    ASSERT_EQ(bellmanMatrix[3].getPath(), p3);
    ASSERT_EQ(bellmanMatrix[4].getPath(), p4);

}

TEST_F(PrimTest, DisconnectedBellmanTest) {
    std::string filename = "resources/shortest_path_disconnected";
    auto g = Graph::readGraphFromFile(filename, true);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto bellmanList = ShortestPath::bellmanFord(listGraph, startingVertex);
    auto bellmanMatrix =  ShortestPath::bellmanFord(matrixGraph, startingVertex);
    ASSERT_EQ(bellmanList, bellmanMatrix);
    ASSERT_EQ(bellmanMatrix[0].getDistance(), 3);
    ASSERT_EQ(bellmanMatrix[1].getDistance(), 1);
    ASSERT_EQ(bellmanMatrix[2].getDistance(), 2);

}