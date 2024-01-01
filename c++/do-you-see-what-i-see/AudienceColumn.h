/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#ifndef AUDIENCE_COLUMN_H
#define AUDIENCE_COLUMN_H

#include <cstdio>
#include <iostream>
#include "MonoStack.h"

using namespace std;

template <typename T>
class AudienceColumn : public MonoStack<T> {
public:
    AudienceColumn();
    void print(int n);
};

// default constructor for AudienceColumn
// makes a decreasing MonoStack of size 10
template<typename T>
AudienceColumn<T>::AudienceColumn() : MonoStack<T>(10, 'd') {}

// printing out the heights 
template<typename T>
void AudienceColumn<T>::print(int n) {
    cout << "In column " << n << " there are " << MonoStack<T>::count  << " that can see. Their heights are: ";
    // separating the numbers at a space
    string delim = "";
    for (int i=MonoStack<T>::count-1; i>=0; i--) {
        cout << delim << MonoStack<T>::arr[i];
        delim =", ";
    }
    cout << " inches." << endl;
}

#endif
