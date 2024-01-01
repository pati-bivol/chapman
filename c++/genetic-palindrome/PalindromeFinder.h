/*
 * Patricia Bivol
 * 2421265
 * bivol@chapman.edu
 * CPSC 350 Section 04
 * PA4
 */

#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include <ostream>
#include <fstream>
#include "DNASeq.h"

class PalindromeFinder {
public:
    // constructor and deconstructor
    PalindromeFinder() = default;
    ~PalindromeFinder() = default;

    static void parse(string s);
};

#endif
