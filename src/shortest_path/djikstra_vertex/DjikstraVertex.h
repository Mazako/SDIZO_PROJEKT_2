#ifndef SDIZO_PROJ_2_DJIKSTRAVERTEX_H
#define SDIZO_PROJ_2_DJIKSTRAVERTEX_H


class DjikstraVertex {
    int v;
    int distance;

public:
    DjikstraVertex(int v, int distance);

    int getV() const;

    int getDistance() const;
};


#endif //SDIZO_PROJ_2_DJIKSTRAVERTEX_H
