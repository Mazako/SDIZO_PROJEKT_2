#include "DisjointNode.h"


int DisjointNode::getValue() const {
    return value;
}

void DisjointNode::setValue(int value) {
    DisjointNode::value = value;
}

DisjointNode *DisjointNode::getParent() const {
    return parent;
}

void DisjointNode::setParent(DisjointNode *parent) {
    DisjointNode::parent = parent;
}

int DisjointNode::getRank() const {
    return rank;
}

void DisjointNode::setRank(int rank) {
    DisjointNode::rank = rank;
}

DisjointNode::DisjointNode(int value) {
    this->value = value;
}
