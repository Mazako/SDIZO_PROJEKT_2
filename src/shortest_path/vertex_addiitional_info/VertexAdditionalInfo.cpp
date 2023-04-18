#include "VertexAdditionalInfo.h"

VertexAdditionalInfo::VertexAdditionalInfo(int vertex, int distance, int predecessor) {
    this->vertex = vertex;
    this->distance = distance;
    this->predecessor = predecessor;
}

int VertexAdditionalInfo::getVertex() const {
    return vertex;
}

int VertexAdditionalInfo::getDistance() const {
    return distance;
}

int VertexAdditionalInfo::getPredecessor() const {
    return predecessor;
}

void VertexAdditionalInfo::setVertex(int vertex) {
    VertexAdditionalInfo::vertex = vertex;
}

void VertexAdditionalInfo::setDistance(int distance) {
    VertexAdditionalInfo::distance = distance;
}

void VertexAdditionalInfo::setPredecessor(int predecessor) {
    VertexAdditionalInfo::predecessor = predecessor;
}
