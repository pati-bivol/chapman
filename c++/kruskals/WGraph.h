#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits> // allows us to get min and max
#include <vector>
#include "Edge.h"

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public:
    WGraph();
    WGraph(unsigned int sz);
    ~WGraph();
    void addEdge(VertexID i, VertexID j, double w); // now includes a double for the weight of the edge
    void removeEdge(VertexID i, VertexID j);
    bool areAdjacent(VertexID i, VertexID j);
    double cheapestCost(VertexID i, VertexID j); // will give us the cheapest path between two vertices
    void calcFW(); // will calculate the Floyd-Warshall algo and create a connectivity matrix that gives us the shortest path from every node to every other node
    void computeMST(); // Compute the minimum spanning tree

private:
    double** m_adj; // Adjacency matrix: is there an edge between two vertices and what's the weight of the edge
    double** m_conn; // Connectivity matrix: more general, is there a path between a start and a finish and what's the cost (all parts summed)
    unsigned int m_size; // number of nodes in WGraph (fixed)

    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> sortedEdges; // Priority queue to store a sorted list of graph edges
    std::set<VertexID> visitedVertices; // Stores the list of vertices already present in the MST. Used to detect loops.
    double** m_mst; // MST adjacency matrix

    void identifyMST();
    double mstCost();
    void printMST();
    bool hasLoops(VertexID node);
    bool dfsLoopSearch(VertexID node, VertexID parent);

};

#endif