#include "ShortestPathDTO.h"

int ShortestPathDTO::getStart() const {
    return start;
}

int ShortestPathDTO::getAnEnd() const {
    return end;
}

int ShortestPathDTO::getDistance() const {
    return distance;
}

const std::vector<int> &ShortestPathDTO::getPath() const {
    return path;
}

ShortestPathDTO::ShortestPathDTO(int start, int anEnd, int distance, const std::vector<int> &path) : start(start),
                                                                                                     end(anEnd),
                                                                                                     distance(distance),
                                                                                                     path(path) {}
