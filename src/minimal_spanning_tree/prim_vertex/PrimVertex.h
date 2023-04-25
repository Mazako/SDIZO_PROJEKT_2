#ifndef SDIZO_PROJ_2_PRIMVERTEX_H
#define SDIZO_PROJ_2_PRIMVERTEX_H


class PrimVertex {
    int v;
    int key;
public:
    PrimVertex(int v, int key);

    int getV() const;

    void setV(int v);

    int getKey() const;

    void setKey(int key);
};


#endif //SDIZO_PROJ_2_PRIMVERTEX_H
