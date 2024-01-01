#include "Model.h"

Model::Model() {}

Model::~Model() {}

// translating a consonant
string Model::translateSingleConsonant(char consonant) {
    string translation;
    translation = consonant;
    translation += 'o';
    translation += consonant;
    return translation;
}

// translating a vowel
string Model::translateSingleVowel(char vowel) {
    string result;
    result = vowel;
    return result;
}
