// header guard
#ifndef MODEL_H
#define MODEL_H

#include <string>
using namespace std;

class Model {
public:
    Model();
    ~Model();
    static string translateSingleConsonant(char consonant);
    static string translateSingleVowel(char vowel);
};

#endif