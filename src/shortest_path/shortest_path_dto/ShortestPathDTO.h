#ifndef SDIZO_PROJ_2_SHORTESTPATHDTO_H
#define SDIZO_PROJ_2_SHORTESTPATHDTO_H

#include <vector>
#include <string>
#include <stdexcept>

class ShortestPathDTO {
private:
    int start;
    int end;
    int distance;
    std::vector<int> path;
public:
    ShortestPathDTO(int start, int anEnd, int distance, const std::vector<int> &path);

    int getStart() const;

    int getAnEnd() const;

    int getDistance() const;

    const std::vector<int> &getPath() const;
};


#endif //SDIZO_PROJ_2_SHORTESTPATHDTO_H
