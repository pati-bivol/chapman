/*
 * Patricia Bivol
 * 2421265
 * bivol@chapman.edu
 * CPSC 350 Section 04
 * PA4
 */

#include "PalindromeFinder.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide the input specification file as a command line argument." << endl;
        return 0;
    }

    fstream file(argv[1]);
    string line;
    while (true) {
        getline(file, line);
        if (line == "END") return 0; // we have reached the last line of the input file

        PalindromeFinder::parse(line); // method for finding the genetic palindromes
    }
}
