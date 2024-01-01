// header guard
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Translator.h"
#include <fstream>
#include <string>

using namespace std;

class FileProcessor {
private:
    Translator translator;
public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputFile, string outputFile);
};

#endif