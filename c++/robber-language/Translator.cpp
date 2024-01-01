#include "Translator.h"

Translator::Translator() {}

Translator::~Translator() {}

// translating a word
string Translator::translateEnglishWord(string englishWord) {
    string translatedWord = "";

    for (char c : englishWord) {
        // creating a copy of char c for the switch case
        char lowerLetter = tolower(c);

        switch (lowerLetter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                // char c is a vowel
                translatedWord += Model::translateSingleVowel(c);
                break;
            default:
                // char is a consonant
                translatedWord += Model::translateSingleConsonant(c);
                break;
        }
    }
    return translatedWord;
}

// translating a sentence
string Translator::translateEnglishSentence(string englishSentence) {
    string translatedSentence;
    string delimiter = "!?.,;:- '";
    size_t prev = 0, pos;
    string token;

    // used source listed in README from lines 42 - 52
    // splitting the sentence at the delimiter to separate the words
    while ((pos = englishSentence.find_first_of(delimiter, prev)) != string::npos) {
        token = englishSentence.substr(prev, pos-prev);
        translatedSentence += translateEnglishWord(token) + englishSentence.at(pos);

        // avoids translating the same word multiple times
        prev = pos+1;
    }

    // if there is no delimiter found and there are words left in the sentence
    if (prev < englishSentence.size()) {
        translatedSentence += translateEnglishWord(englishSentence.substr(prev));
    }

    return translatedSentence;
}
