#ifndef SDIZO_PROJ_2_EDGE_H
#define SDIZO_PROJ_2_EDGE_H


class Edge {
    int v1;
    int v2;
    int weight;
public:
    Edge(int v1, int v2, int weight);

    int getV1() const;

    int getV2() const;

    int getWeight() const;
};


#endif //SDIZO_PROJ_2_EDGE_H
