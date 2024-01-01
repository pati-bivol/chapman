#ifndef CHAPMANDB_H
#define CHAPMANDB_H

#include "LazyBST.h"
#include "Database.h"
#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

class ChapmanDB {
public:
    ChapmanDB();
    ~ChapmanDB();

    void start();

private:
    void printMenu();

    Database db;
};

#endif
