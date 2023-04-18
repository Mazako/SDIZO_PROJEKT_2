#ifndef SDIZO_PROJ_2_VERTEXADDITIONALINFO_H
#define SDIZO_PROJ_2_VERTEXADDITIONALINFO_H


class VertexAdditionalInfo {
    int vertex;
    int distance;
    int predecessor;
public:
    VertexAdditionalInfo(int vertex, int distance, int predecessor);

    int getVertex() const;

    int getDistance() const;

    int getPredecessor() const;

    void setVertex(int vertex);

    void setDistance(int distance);

    void setPredecessor(int predecessor);
};


#endif //SDIZO_PROJ_2_VERTEXADDITIONALINFO_H
