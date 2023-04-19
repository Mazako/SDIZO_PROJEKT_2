#ifndef SDIZO_PROJ_2_DISJOINTNODE_H
#define SDIZO_PROJ_2_DISJOINTNODE_H


class DisjointNode {
    int value;
    DisjointNode* parent;
    int rank;
public:
    DisjointNode(int value);

    int getValue() const;

    void setValue(int value);

    DisjointNode *getParent() const;

    void setParent(DisjointNode *parent);

    int getRank() const;

    void setRank(int rank);

};


#endif //SDIZO_PROJ_2_DISJOINTNODE_H
