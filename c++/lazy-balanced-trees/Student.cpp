#include "Student.h"

// default constructor
Student::Student() {
}

// overloaded constructor
Student::Student(int id) : id(id) {
}

// deconstructor
Student::~Student() {
}

istream &operator>>(istream &inputStream, Student &student) {
    string eol;

    inputStream >> student.id; getline(cin, eol);
    getline(cin, student.name);
    getline(cin, student.level);
    getline(cin, student.major);
    cin >> student.gpa; getline(cin, eol);

    return inputStream;
}

ostream &operator<<(ostream &outputStream, const Student &student) {
    outputStream
    << student.id << "; " << student.name << "; " << student.level << "; "
    << student.major << "; " << student.gpa << "; " << student.advisor << ".";
    return outputStream;
}

// method returning true if the Student is a valid Student
bool Student::isValid() {
    return id > 0 && !name.empty() && !level.empty() && !major.empty() && gpa >= 0 && gpa <= 4;
}

// all lines below are operators for comparing

bool Student::operator==(Student &other) {
    return id == other.id;
}

bool Student::operator<(Student &other) {
    return id < other.id;
}

bool Student::operator>(Student &other) {
    return id > other.id;
}

bool Student::operator!=(Student &other) {
    return id != other.id;
}



