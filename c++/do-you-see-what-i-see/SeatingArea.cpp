/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#include <string>
#include "SeatingArea.h"

using std::string;
using std::fstream;
using std::stringstream;

SeatingArea::SeatingArea(string inputFile) {
    fstream file(inputFile);
    string num;
    string line;

    getline(file, line); // Skip the first line - BEGIN
    getline(file, line); // This is our first set of numbers.

    columnCount = countColumns(line);

    while (line != "END.") {
        addRow(line);
        getline(file, line);
    }
}

// counting how many columns there are in our input file 
int SeatingArea::countColumns(string line) {
    // starting at 1 because we are using spaces to count 
    // there will be 1 less space than numbers
    int result = 1;
    for (int i=0; i<line.size(); i++) {
        if (line.at(i) == ' ') {
            result++;
        }
    }
    return result;
}

void SeatingArea::addRow(string line) {
    // if the array is full make a new one of twice the size and delete the old one 
    if (rowCount == maxSize) {
        string *temp = new string[2 * maxSize];
        for (int i = 0; i < maxSize; ++i) {
            temp[i] = rows[i];
        }
        maxSize *= 2;
        delete[] rows;
        rows = temp;
    }

    rows[rowCount++] = line;
}

// getting the heights of everyone in the rows and storing them
float *SeatingArea::getRowHeights(int n) {
    float result[columnCount];
    string num;

    stringstream ss(rows[n]);
    for (int i = 0; i < columnCount; i++) {
        getline(ss, num, ' ');
        result[i] = std::stof(num);
    }

    return result;
}

int SeatingArea::getColumnCount() {
    return columnCount;
}

int SeatingArea::getRowCount() {
    return rowCount;
}

SeatingArea::~SeatingArea() {
    delete[] rows;
}



