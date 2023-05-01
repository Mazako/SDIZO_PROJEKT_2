//
// Created by mazak on 27.04.23.
//

#include "DjikstraVertex.h"

DjikstraVertex::DjikstraVertex(int v, int distance) : v(v), distance(distance) {}

int DjikstraVertex::getV() const {
    return v;
}

int DjikstraVertex::getDistance() const {
    return distance;
}
