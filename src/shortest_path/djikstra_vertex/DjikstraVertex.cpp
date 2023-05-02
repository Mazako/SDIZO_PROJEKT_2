#include "DjikstraVertex.h"

DjikstraVertex::DjikstraVertex(int v, int distance) : v(v), distance(distance) {}

int DjikstraVertex::getV() const {
    return v;
}

int DjikstraVertex::getDistance() const {
    return distance;
}

void DjikstraVertex::setDistance(int distance) {
    DjikstraVertex::distance = distance;
}
