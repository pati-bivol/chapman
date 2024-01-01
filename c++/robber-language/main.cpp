#include <iostream>
#include "FileProcessor.h"

using namespace std;

int main() {
    FileProcessor fileProcessor = FileProcessor();
    fileProcessor.processFile("sampleInputFile.txt", "sampleOutputFile.html");

    return 0;
}