#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "LazyBST.h"
#include "Student.h"
#include <iostream>

using namespace std;

// Faculty records contain an integer Faculty ID, a string name, a string level
// (lecturer, assistant prof, associate prof, etc.), a string department, and a
// list of integers corresponding to all of the faculty member’s advisees’ ids.
//
// This class will also require overloaded operators.
class Faculty {
public:
    int id;
    string name;
    string level;
    string department;
    LazyBST<Student> advisees;

    Faculty();
    Faculty(int id);
    ~Faculty();

    bool isValid();
    bool operator!=(Faculty& other);
    bool operator==(Faculty& other);
    bool operator<(Faculty& other);
    bool operator>(Faculty& other);
    friend ostream& operator << (ostream& outputStream, const Faculty& facultyMember); // output
    friend istream& operator >> (istream& inputStream, Faculty& facultyMember); //input
};

#endif
