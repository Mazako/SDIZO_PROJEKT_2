#include "gtest/gtest.h"
#include "graph/Graph.h"
#include "shortest_path/ShortestPath.h"
#include "graph/list/ListGraph.h"
#include "graph/matrix/MatrixGraph.h"

class DjikstraTest : public ::testing::Test {

};

TEST_F(DjikstraTest, BasicDjikstraTest1) {
    std::string filename = "resources/shortest_path_basic_1";
    auto g = Graph::readGraphFromFile(filename, true);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto djikstaList = ShortestPath::djikstra(listGraph, startingVertex);
    auto djikstraMatrix =  ShortestPath::djikstra(matrixGraph, startingVertex);
    ASSERT_EQ(djikstaList[0].getDistance(), 7);
    ASSERT_EQ(djikstraMatrix[0].getDistance(), 7);
    ASSERT_EQ(djikstaList[1].getDistance(), 9);
    ASSERT_EQ(djikstraMatrix[1].getDistance(), 9);
    ASSERT_EQ(djikstaList[2].getDistance(), 16);
    ASSERT_EQ(djikstraMatrix[2].getDistance(), 16);
    ASSERT_EQ(djikstaList[3].getDistance(), 19);
    ASSERT_EQ(djikstraMatrix[3].getDistance(), 19);
    ASSERT_EQ(djikstraMatrix[4].getDistance(), 17);
    ASSERT_EQ(djikstaList[4].getDistance(), 17);
}

TEST_F(DjikstraTest, BasicDjikstraTest2) {
    std::string filename = "resources/shortest_path_basic_2";
    auto g = Graph::readGraphFromFile(filename, true);
    auto* listGraph = dynamic_cast<ListGraph *>(std::get<0>(g));
    auto* matrixGraph = dynamic_cast<MatrixGraph *>(std::get<1>(g));
    int startingVertex = std::get<2>(g);
    auto djikstaList = ShortestPath::djikstra(listGraph, startingVertex);
    auto djikstraMatrix =  ShortestPath::djikstra(matrixGraph, startingVertex);
    ASSERT_EQ(dji)
    ASSERT_EQ(djikstaList[0].getDistance(), 1);
    ASSERT_EQ(djikstraMatrix[0].getDistance(), 1);
    ASSERT_EQ(djikstaList[1].getDistance(), 4);
    ASSERT_EQ(djikstraMatrix[1].getDistance(), 4);
    ASSERT_EQ(djikstaList[2].getDistance(), 3);
    ASSERT_EQ(djikstraMatrix[2].getDistance(), 3);
    ASSERT_EQ(djikstaList[3].getDistance(), 6);
    ASSERT_EQ(djikstraMatrix[3].getDistance(), 6);
    ASSERT_EQ(djikstraMatrix[4].getDistance(), 7);
    ASSERT_EQ(djikstaList[4].getDistance(), 7);

    ASSERT_EQ(djikstaList[0].getPath(), std::vector<int>{0, 1})
    ASSERT_EQ([0].getPath(), std::vector<int>{0, 1})
}