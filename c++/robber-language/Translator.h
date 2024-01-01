// header guard
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"
#include <string>

using namespace std;

class Translator {
public:
    Translator();
    ~Translator();
    string translateEnglishWord(string englishWord);
    string translateEnglishSentence(string englishSentence);
};

#endif