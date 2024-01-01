#include "WGraph.h"
using namespace std;

bool recalcFW;

WGraph::WGraph(){
    m_size = 0;
    m_adj = NULL;
    m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
    m_size = sz;
    //allocate sz * sz adj matrix
    m_adj = new double*[sz];
    m_conn = new double*[sz];
    m_mst = new double*[sz];
    for(int i = 0; i < m_size; ++i){
        m_adj[i] = new double[sz];
        m_conn[i] = new double[sz];
        m_mst[i] = new double[sz];
    }
    //start with edges
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_adj[i][j] = std::numeric_limits<double>::max();
            m_conn[i][j] = std::numeric_limits<double>::max();
        }
    }

    recalcFW = false;
}

WGraph::~WGraph(){
    // release memory - let's actually do it in class for once
    for (int i = 0; i < m_size; ++ i){
        delete m_adj[i];
        delete m_conn[i];
        delete m_mst[i];
    }
    delete[] m_adj;
    delete[] m_conn;
    delete[] m_mst;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
    if(i < m_size && j < m_size){
        m_adj[i][j] = w;
        m_adj[j][i] = w;
    }
    // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
    recalcFW = true;
}

void WGraph::removeEdge(VertexID i, VertexID j){
    if(i < m_size && j < m_size){
        m_adj[i][j] = std::numeric_limits<double>::max();
        m_adj[j][i] = std::numeric_limits<double>::max();
    }
    // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
    recalcFW = true;
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
    return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
    // set the conn matrix equal to adj matrix
    for (int i = 0; i < m_size; ++i){
        for (int j = 0; j < m_size; ++j){
            m_conn[i][j] = m_adj[i][j];
        }
    }

    // start FW
    for (int im = 0; im < m_size; ++im){ // intermediate points
        for (int source = 0; source < m_size; ++source){ // source -> starting point
            for (int sink = 0; sink < m_size; ++sink){ // sink -> ending point
                if (source == sink){
                    continue;
                } else if ( m_conn[source][im] != std::numeric_limits<double>::max() &&
                            m_conn[im][sink] != std::numeric_limits<double>::max() &&
                            m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){

                    m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];

                }
            }
        }
    }
    recalcFW = false;
}

double WGraph::cheapestCost(VertexID i, VertexID j){
    if (recalcFW){
        calcFW();
    }
    return m_conn[i][j];
}

void WGraph::computeMST() {
    identifyMST();
    cout << "MST Cost: " << mstCost() << endl;
    cout << "Adjacency matrix: " << endl;
    printMST();
}

void WGraph::identifyMST() {
    // Reset the list of sorted edges and the set of used vertices
    sortedEdges = priority_queue<Edge, vector<Edge>, greater<>>();

    // Sort all graph edges.
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (m_adj[i][j] != 0) {
                sortedEdges.push(Edge(i, j, m_adj[i][j]));
            }
        }
    }

    // Add all edges to the MST, cheapest one first, making sure we're not introducing any loops.
    while (!sortedEdges.empty()) {
        Edge edge = sortedEdges.top();
        int i = edge.sourceVertexId;
        int j = edge.destinationVertexId;

        // Add the edge to the MST.
        m_mst[i][j] = edge.weight;
        m_mst[j][i] = edge.weight;

        // If it results in a loop, remove it.
        if (hasLoops(i)) {
            m_mst[i][j] = 0;
            m_mst[j][i] = 0;
        }

        sortedEdges.pop();
    }
}

bool WGraph::hasLoops(VertexID node) {
    visitedVertices = set<VertexID>();
    return dfsLoopSearch(node, node);
}

bool WGraph::dfsLoopSearch(VertexID node, VertexID parent) {
    if (visitedVertices.find(node) != visitedVertices.end()) {
        return true;
    }

    // Keep track of the vertices that we already visited.
    visitedVertices.insert(node);

    // Traverse the graph making sure we're not returning to the node we're coming from (parent).
    // If we stumble upon a vertex that has already been visited that means we have a loop.
    for (int i=0; i<m_size; i++) {
        if (m_mst[node][i] != 0 && i != parent && dfsLoopSearch(i, node)) {
            return true;
        }
    }

    return false;
}

double WGraph::mstCost() {
    double cost = 0;

    // Since we're dealing with an undirected graph, we should only look at either top or bottom half of the
    // adjacency matrix when calculating the total cost of the MST.
    for (int i = 0; i < m_size; ++i) {
        for (int j = i+1; j < m_size; ++j) {
                cost += m_mst[i][j];
        }
    }

    return cost;
}

void WGraph::printMST() {
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            cout << m_mst[i][j] << " ";
        }
        cout << endl;
    }
}
