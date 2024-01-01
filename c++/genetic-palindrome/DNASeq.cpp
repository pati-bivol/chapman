/*
 * Patricia Bivol
 * 2421265
 * bivol@chapman.edu
 * CPSC 350 Section 04
 * PA4
 */

#include "DNASeq.h"

// default constructor
DNASeq::DNASeq() = default;

// overloaded constructor
DNASeq::DNASeq(string &s) {
    // adding each char in given string to a sequence
    for (char c : s) {
        sequence.addBack(c);
    }
}

// print method
void DNASeq::print() {
    for (int i=0; i<sequence.size(); i++) {
        cout << sequence.get(i);
    }
}

// method returning the complement of the sequence
DNASeq DNASeq::complement() {
    DNASeq result;

    // if the sequence is not a valid sequence, return
    if (!isValid()) return result;

    // finding the complement for each char in the sequence
    for (int i=0; i<sequence.size(); i++) {
        char c = sequence.get(i);
        switch (c) {
            case 'A' : c = 'T'; break;
            case 'T' : c = 'A'; break;
            case 'C' : c = 'G'; break;
            default  : c = 'C'; break; // we know this is a valid genetic sequence, so 'G->C' is the only option left
        }
        result.sequence.addBack(c); // adding each complement to the back of the result
    }

    return result;
}

// method returning a substring
DNASeq DNASeq::substring(int s, int e) {
    // substring is not a valid palindrome
    if (!isValid()) return {};

    if (s < 0) s = 0; // substring should start at the beginning of the genetic sequence
    if (e >= sequence.size()) e = sequence.size() - 1; // substring should end at the end of the genetic sequence

    string result;
    for (int i=s; i<=e; i++) {
        result += sequence.get(i); // using s and e to get the substring
    }

    return {result};
}

// method determining if the sequence is a valid genetic sequence
bool DNASeq::isValid() {
    if (sequence.size() == 0) return false; // there is no sequence

    // iterating through to check each char
    for (int i=0; i<sequence.size(); i++) {
        char c = sequence.get(i);
        // if the char is not 'A','C','T',or 'G' it is not a valid genetic sequence
        if (c != 'A' && c != 'C' && c != 'T' && c != 'G') return false;
    }

    return true;
}

// method checking if the sequence is a genetic palindrome
bool DNASeq::isGeneticPalindrome() {
    DNASeq reversed = complement(); // the sequence's complement
    DNASeq original = reversed.complement(); // the sequence

    for (int i=0; i<sequence.size()/2; i++) {
        // checking if the reversed and original are the same
        if (original.sequence.removeFront() != reversed.sequence.removeBack()) {
            return false;
        }
    }

    return true;
}

int DNASeq::size() {
    return sequence.size();
}

