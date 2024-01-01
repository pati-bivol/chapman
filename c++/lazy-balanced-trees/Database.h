#ifndef DATABASE_H
#define DATABASE_H

#include "Faculty.h"

class Database {
public:
    Database();
    ~Database();

    void printStudents(ostream& out);
    void printFacultyMembers(ostream& out);
    void print(ostream& out, Student student);
    void print(ostream& out, Faculty faculty);
    void add(Student& student);
    void add(Faculty& facultyMember);
    void remove(Student student);
    void remove(Faculty facultyMember);
    void changeAdvisor(int studentId, int facultyMemberId);
    void removeAdvisee(int facultyMemberId, int studentId);

private:
    LazyBST<Student> studentTable = LazyBST<Student>();
    LazyBST<Faculty> facultyTable = LazyBST<Faculty>();
};
#endif
