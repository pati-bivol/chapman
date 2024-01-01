CPSC 350: Data Structures and Algorithms
Fall 2023
 Programming Assignment 4: Genetic Palindromes
Due: See Canvas for due date
The Assignment
In this assignment, we will explore the properties of DNA and use LinkedLists to identify interesting structural properties of the genetic code.

As you know, DNA consists of strands of nucleotides, each of which can take on one of four possible types:
Adenine (A)
Cytosine (C)
Thymine (T)
Guanine (G)

We can represent a DNA sequence as a string where each character in the string represents a single nucleotide using the above abbreviations.

In natural language, such as English, a palindrome is a string that is spelled the same way forward and backwards (e.g. “wow”). Palindromes also exist in DNA, but this genetic version is slightly different. To determine if a DNA sequence is a palindrome, we must first compute its complement. To do this, we simply start with the original string and:
Replace all A’s with T’s
Replace all T’s with A’s
Replace all C’s with G’s
Replace all G’s with C’s

If we read the complement in reverse order and it matches the original sequence, the original sequence was indeed a genetic palindrome. For example, ACCTAGGT is a palidrome because its complement is TGGATCCA, and if we read the complement in reverse, it matches the original sequence.
 
The Program
Your task is to write a program that reads a file consisting of DNA sequences (1 per line), analyzing their structure. The program should take the file name as a command line argument to main. The file will consist of N lines representing separate DNA sequences. The last line of the fine will be the sentinel “END.”

Your program should represent each DNA sequence as a doubly-linked list of characters. You should start with the DblList implementation we coded together in class, adding any error handling as appropriate. Failure to represent the strings in this way will result in a 50% deduction.

When your program runs, for each DNA sequence in the provided file it should:
Print the full sequence and whether it is a genetic palindrome to the terminal, assuming the sequence is valid. If the sequence is not valid (contains characters other than ACTG), it should say so and move on to the next sequence.
If the sequence is valid, identify all substrings (of lengths greater than 4 and less than 
the length of the sequence) of the DNA sequence which are themselves genetic palindromes. The substrings should be printed from smallest length to largest length to the terminal.

The Design
Your simulation will consist of the following classes (bolded classes are required):
DblList - the doubly linked list template class
DNASeq - a class to represent a single DNA sequence. It should contain:
A default constructor
A default destructor
An overloaded constructor that creates a sequence from a character string
A method DNASeq complement()that returns a DNA Sequence representing the complement.
A method DNASeq substring(int s, int e)that returns a DNA Sequence based on the substring from position s (inclusive) to position e (exclusive).
A method bool isGeneticPalindrome()that returns true if the sequence is a genetic palindrome and false otherwise.
PalindromeFinder - the class to determine whether a sequence is a palindrome and whether it contains substrings that are genetic palindromes.

You should also provide a main.cpp to run the program, which takes the input specification file as a command line argument.
Rules of Engagement
You may NOT use any non-primitive data structures other than what we have implemented in class. You may not use any data structures from the C++ STL. Of course, to do the file processing you may use any of the standard C++ IO classes.
For this assignment, you must work individually.
Develop using VSCode and make sure your code runs correctly with g++ using the course docker container.
Feel free to use whatever textbooks or Internet sites you want to refresh your memory with C++ IO operations, just cite them in a README file turned in with your code.  All code you write, of course, must be your own. In your README please be sure to include the g++ command for compiling your code.
Due Date
This assignment is due at 11:59 pm on see Canvas for due date. Submit all your commented code as a zip file to canvas. The name of the zip file should be LastName_FirstInitial_A4.zip
 
Grading
Grades will be based on correctness, adherence to the guidelines, and code quality (including the presence of meaningful comments).  An elegant, OO solution will receive much more credit than procedural spaghetti code.  I assume you are familiar with the standard style guide for C++, which you should follow.  (See the course page on Canvas for a C++ style guide and Coding Documentation Requirements.)
 
Code that does not follow the specification EXACTLY will receive an automatic 25% deduction. Code that does not compile will receive an automatic 50% deduction.

