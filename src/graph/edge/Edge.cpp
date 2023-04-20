//
// Created by mazak on 20.04.23.
//

#include "Edge.h"

int Edge::getV1() const {
    return v1;
}

int Edge::getV2() const {
    return v2;
}

int Edge::getWeight() const {
    return weight;
}

Edge::Edge(int v1, int v2, int weight) : v1(v1), v2(v2), weight(weight) {}
