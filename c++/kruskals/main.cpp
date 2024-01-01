#include <iostream>
#include <fstream>
#include "WGraph.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide the input specification file as a command line argument." << endl;
        return 1;
    }

    int n;
    double weight;
    fstream file(argv[1]);

    // Construct the weighted graph from the input file.
    file >> n;
    WGraph myWG(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            file >> weight;
            myWG.addEdge(i, j,weight);
        }
    }

    // If we have a valid input file compute the MST. Return en error code otherwise.
    string line;
    file >> line;
    if (line == "END") {
        myWG.computeMST();
        return 0;
    } else {
        cout << "Invalid input file." << endl;
        return 1;
    }
}
