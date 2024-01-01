
#include "Faculty.h"

using namespace std;

// default constructor
Faculty::Faculty() {
}

// overloaded constructor
Faculty::Faculty(int id) : id(id) {
}

// deconstructor
Faculty::~Faculty() {
}

bool Faculty::isValid() { // returns true if the faculty member is a valid faculty member
    return id > 0 && !name.empty() && !level.empty() && !department.empty();
}

istream &operator>>(istream &inputStream, Faculty &faculty) {
    string eol;

    inputStream >> faculty.id; getline(cin, eol);
    getline(cin, faculty.name);
    getline(cin, faculty.level);
    getline(cin, faculty.department);

    return inputStream;
}

ostream &operator<<(ostream &outputStream, const Faculty &faculty) {
    outputStream
            << faculty.id << "; " << faculty.name << "; " << faculty.level << "; "
            << faculty.department << ".";
    return outputStream;
}

// all lines below are operators for comparing

bool Faculty::operator==(Faculty &other) {
    return id == other.id;
}

bool Faculty::operator!=(Faculty &other) {
    return id != other.id;
}

bool Faculty::operator<(Faculty &other) {
    return id < other.id;
}

bool Faculty::operator>(Faculty &other) {
    return id > other.id;
}

