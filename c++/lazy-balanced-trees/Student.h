#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

// Student records will be stored in a *Student* class. Student records contain a unique
// student ID (an integer), a string name field, a string level field (Freshman, Sophomore,
// etc.), a string major field, a double GPA field, and an integer advisor field, which
// will contain the Faculty ID of their advisor. These are the only fields the class contains.
//
// The Student class must overload equality, less than, greater than operators, etc. so that
// we can compare them to one another.
class Student {
public:
    int id = 0;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;

    Student();
    Student(int id);
    ~Student();

    bool isValid();
    bool operator!=(Student& other);
    bool operator==(Student& other);
    bool operator<(Student& other);
    bool operator>(Student& other);
    friend ostream& operator << (ostream& outputStream, const Student& student); // output
    friend istream& operator >> (istream& inputStream, Student& student); //input

};

#endif
