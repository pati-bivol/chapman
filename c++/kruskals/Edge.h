#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    int sourceVertexId;
    int destinationVertexId;
    double weight;

    Edge(int source, int destination, double weight);
    bool operator!=(Edge& other);
    bool operator==(Edge& other);
    bool operator<(Edge& other);
    bool operator>(Edge& other);
};

#endif 
