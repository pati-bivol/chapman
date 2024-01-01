#include "Database.h"

// default constructor
Database::Database() {
}

// deconstructor
Database::~Database() {
}

// method adding a student to the database
void Database::add(Student &student) {
    // student is not a valid student
    if (!student.isValid()) {
        cout << "Invalid Student details. Try again." << endl;
        return;
    }

    // student is already recorded
    if (studentTable.contains(student)) {
        cout << "A Student record with this Id (" << student.id << ") already exists. Try again." << endl;
        return;
    }

    // adding the student
    studentTable.insert(student);
    cout << "Student added: " << student << endl;
}

// method adding a faculty member to the database
void Database::add(Faculty &facultyMember) {
    // not a valid faculty member
    if (!facultyMember.isValid()) {
        cout << "Invalid Faculty Member details. Try again." << endl;
        return;
    }

    // faculty member already exists in database
    if (facultyTable.contains(facultyMember)) {
        cout << "A Faculty Member record with this Id (" << facultyMember.id << ") already exists. Try again." << endl;
        return;
    }

    // adding faculty member to database
    facultyTable.insert(facultyMember);
    cout << "Faculty Member added: " << facultyMember << endl;
}

void Database::remove(Student student) {
    if (!studentTable.contains(student)) {
        cout << "Student record with given Id (" << student.id << ") not found. Try again." << endl;
        return;
    }

    // Load the student from the database given its id.
    student = studentTable.find(student);

    // Since the student is being deleted, the faculty member is losing their advisee.
    removeAdvisee(student.advisor, student.id);

    studentTable.remove(student);
    cout << "Student removed: " << student << endl;
}

void Database::remove(Faculty facultyMember) {
    if (!facultyTable.contains(facultyMember)) {
        cout << "Faculty Member record with given Id (" << facultyMember.id << ") not found. Try again." << endl;
        return;
    }

    // Load the faculty member from the database given its id.
    facultyMember = facultyTable.find(facultyMember);

    // Load all advisees for the given faculty member.
    Student* advisees = facultyMember.advisees.all();

    // Reset the Advisor for each of the affected students.
    for (int i=0; i<facultyMember.advisees.size(); i++) {
        removeAdvisee(facultyMember.id, advisees[i].id);
    }

    // Now we can delete the faculty member from the database.
    facultyTable.remove(facultyMember);

    cout << "Faculty member removed: " << facultyMember << endl;
}

void Database::changeAdvisor(int studentId, int facultyMemberId) {
    if (!studentTable.contains(studentId)) {
        cout << "Student record with given Id (" << studentId << ") not found. Try again." << endl;
        return;
    }

    if (facultyMemberId != 0 && !facultyTable.contains(facultyMemberId)) {
        cout << "Faculty Member record with given Id (" << facultyMemberId << ") not found. Try again." << endl;
        return;
    }

    Student& student = studentTable.find(studentId);

    if (student.advisor == facultyMemberId) {
        cout << "Faculty Member already an advisor for Student." << endl;
        return;
    }

    // If the Student already had an advisor, remove the Student as an advisee from the
    // previous faculty member record.
    removeAdvisee(student.advisor, studentId);

    // Update the advisor field on the Student table.
    student.advisor = facultyMemberId;

    // Add the Student as a new advisee on the given faculty member.
    if (facultyMemberId != 0) {
        Faculty& newAdvisor = facultyTable.find(facultyMemberId);
        newAdvisor.advisees.insert(student);
        cout << "Advisee added for Faculty Member: " << newAdvisor << endl;
    }

    cout << "Advisor added for Student: " << student << endl;
}

void Database::removeAdvisee(int facultyMemberId, int studentId) {
    if (facultyMemberId == 0) {
        return;
    }

    if (!studentTable.contains(studentId)) {
        cout << "Student record with given Id (" << studentId << ") not found. Try again." << endl;
        return;
    }

    if (!facultyTable.contains(facultyMemberId)) {
        cout << "Faculty Member record with given Id (" << facultyMemberId << ") not found. Try again." << endl;
        return;
    }

    // Update the advisor field on the Student table.
    Student& student = studentTable.find(studentId);
    if (student.advisor == 0) {
        cout << "Student has no Faculty Member advisor." << endl;
        return;
    }

    student.advisor = 0;
    cout << "Advisor removed for Student: " << student << endl;

    // Remove the student from the advisee list on the faculty member.
    Faculty& facultyMember = facultyTable.find(facultyMemberId);
    facultyMember.advisees.remove(student);
    cout << "Advisee removed from Faculty Member: " << facultyMember << endl;
}

// printing the full list of students
void Database::printStudents(ostream &out) {
    out << "Full list of Students:" << endl;

    if (studentTable.size() ==0) {
        out << "<empty>" << endl;
        return;
    }

    Student* students = studentTable.all();
    for (int i=0; i<studentTable.size(); i++) {
        out << students[i] << endl;
    }
}

// Printing the full list of faculty members
void Database::printFacultyMembers(ostream &out) {
    out << "Full list of Faculty Members:" << endl;

    if (facultyTable.size() == 0) {
        out << "<empty>" << endl;
        return;
    }

    Faculty* facultyMembers = facultyTable.all();
    for (int i=0; i<facultyTable.size(); i++) {
        out << facultyMembers[i] << endl;
    }
}

void Database::print(ostream &out, Student student) {
    if (!studentTable.contains(student)) {
        cout << "Student record with given Id (" << student.id << ") not found. Try again." << endl;
        return;
    }

    out << "Found Student record: " << studentTable.find(student) << endl;
}

void Database::print(ostream &out, Faculty facultyMember) {
    if (!facultyTable.contains(facultyMember)) {
        cout << "Faculty Member record with given Id (" << facultyMember.id << ") not found. Try again." << endl;
        return;
    }

    out << "Found Faculty Member record: " << facultyTable.find(facultyMember) << endl;
}
