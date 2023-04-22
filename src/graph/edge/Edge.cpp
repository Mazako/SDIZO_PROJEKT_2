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

bool Edge::operator<(const Edge &otherEdge) const {
    return weight < otherEdge.weight;
}

std::string Edge::toString() const {
    return "(" + std::to_string(v1) + ", " + std::to_string(v2) + ") -> " + std::to_string(weight);
}
