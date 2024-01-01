/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#ifndef SEATING_AREA_H
#define SEATING_AREA_H

#include <string>
#include <fstream>
#include <sstream>

using std::string;

class SeatingArea {
public:
    SeatingArea(string inputFile);
    ~SeatingArea();

    int getColumnCount();
    int getRowCount();
    float* getRowHeights(int n);

private:
    string* rows = new string[10];
    int rowCount = 0;
    int columnCount = 0;
    int maxSize = 10;

    int countColumns(string line);
    void addRow(string line);
};

#endif
