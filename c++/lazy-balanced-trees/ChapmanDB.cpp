#include "ChapmanDB.h"

// default constructor
ChapmanDB::ChapmanDB() {
    db = Database();
}

// deconstructor
ChapmanDB::~ChapmanDB() {
}

void ChapmanDB::start() {
    ofstream file;
    file.open("runLog.txt");

    Student student;
    Faculty faculty;
    int input, id, otherId;

    // to select an input, the user must return a number 1-11
    while (true) {
        printMenu();
        cin >> input;
        switch (input) {
            // user returns 1
            case 1:
                // print all students
                db.printStudents(cout);
                break;
            case 2:
                // print all faculty members
                db.printFacultyMembers(cout);
                break;
            case 3:
                // Find and display student information given the student id
                cout << "Please provide Student Id:" << endl;
                cin >> id;
                db.print(cout, Student(id));
                break;
            case 4:
                // Find and display faculty information given the faculty id
                cout << "Please provide Faculty Member Id:" << endl;
                cin >> id;
                db.print(cout, Faculty(id));
                break;
            case 5:
                // add a new student
                cout << "Please provide Student Id, Name, Level, Major, and their GPA (from 0.0 to 4.0), each input on a new line:" << endl;
                cin >> student;
                db.add(student);
                break;
            case 6:
                // Delete a student given the id
                cout << "Please provide the Student Id to be deleted:" << endl;
                cin >> id;
                db.remove(Student(id));
                break;
            case 7:
                // Add a new faculty member
                cout << "Please provide Faculty Member Id, Name, Level, and Department, each input on a new line:" << endl;
                cin >> faculty;
                db.add(faculty);
                break;
            case 8:
                // Delete a faculty member given the id.
                cout << "Please provide the Faculty Member Id to be deleted:" << endl;
                cin >> id;
                db.remove(Faculty(id));
                break;
            case 9:
                // Change a student’s advisor given the student id and the new faculty id.
                cout << "Please provide the Student Id and the Faculty Member Id (0 for no advisor), each input on a new line:" << endl;
                cin >> id;
                cin >> otherId;
                db.changeAdvisor(id, otherId);
                break;
            case 10:
                // Remove an advisee from a faculty member given the ids
                cout << "Please provide the Student Id and the Faculty Member Id, each input on a new line:" << endl;
                cin >> id;
                cin >> otherId;
                db.removeAdvisee(otherId, id);
                break;
            case 11:
                // exit
                db.printStudents(file);
                db.printFacultyMembers(file);
                return;
            default:
                // the user did not return a number 1-11
                cout << "Input not recognized! Try again." << endl;
        }

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
    }
}

// printing the options
void ChapmanDB::printMenu() {
    cout << "================================================================" << endl;
    cout << "Welcome to ChapmanDB! Please choose one of the following options:" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the student id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Add a new student" << endl;
    cout << "6. Delete a student given the id" << endl;
    cout << "7. Add a new faculty member" << endl;
    cout << "8. Delete a faculty member given the id." << endl;
    cout << "9. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "10. Remove an advisee from a faculty member given the ids" << endl;
    cout << "11. Exit" << endl;
    cout << ">>  ";
}

