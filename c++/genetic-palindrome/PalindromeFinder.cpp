/*
 * Patricia Bivol
 * 2421265
 * bivol@chapman.edu
 * CPSC 350 Section 04
 * PA4
 */

#include "PalindromeFinder.h"

void PalindromeFinder::parse(string s) {
    if (s.empty()) { // there is no sequence
        cout << "''";
    } else { // printing out the sequence
        cout << s;
    }

    DNASeq sequence = DNASeq(s); // creating a DNASeq from string s
    if (!sequence.isValid()) { // sequence is invalid
        cout << " - INVALID" << endl;
        return;
    }

    if (!sequence.isGeneticPalindrome()) { // sequence is not a genetic palindrome
        cout << " - Not a Genetic Palindrome" << endl;
        return;
    }

    cout << " - Genetic Palindrome" << endl; // sequence is a genetic palindrome

    DNASeq substr;
    // sliding window loop for the substrings
    // will print out the substring is order of greatest to least without having to sort them using an array
    for (int i=4; i<sequence.size()-1; i++) {
        for (int j=0; j+i<sequence.size(); j++) {
            substr = sequence.substring(j, i+j);

            // if the substring is a genetic palindrome, then print
            if (substr.isGeneticPalindrome()) {
                cout << " Substring ";
                substr.print();
                cout << " - Genetic Palindrome" << endl;
            }
        }
    }
}
