#include "PrimVertex.h"

PrimVertex::PrimVertex(int v, int key) : v(v), key(key) {}

int PrimVertex::getV() const {
    return v;
}

void PrimVertex::setV(int v) {
    PrimVertex::v = v;
}

int PrimVertex::getKey() const {
    return key;
}

void PrimVertex::setKey(int key) {
    PrimVertex::key = key;
}
