
#include "Edge.h"

Edge::Edge(int source, int destination, double weight)  : sourceVertexId(source), destinationVertexId(destination), weight(weight) {
}

bool Edge::operator==(Edge &other) {
    return weight == other.weight;
}

bool Edge::operator!=(Edge &other) {
    return weight != other.weight;
}

bool Edge::operator<(Edge &other) {
    return weight < other.weight;
}

bool Edge::operator>(Edge &other) {
    return weight > other.weight;
}
