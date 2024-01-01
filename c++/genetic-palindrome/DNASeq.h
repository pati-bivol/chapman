/*
 * Patricia Bivol
 * 2421265
 * bivol@chapman.edu
 * CPSC 350 Section 04
 * PA4
 */

#ifndef DNA_SEQ_H
#define DNA_SEQ_H

#include <string>
#include "DblList.h"

using namespace std;

class DNASeq {
public:
    DNASeq();
    ~DNASeq() = default; // deconstructor
    DNASeq(string &s);
    DNASeq substring(int s, int e);
    bool isGeneticPalindrome();
    bool isValid();
    int size();
    void print();

private:
    DblList<char> sequence;
    DNASeq complement();
};

#endif
