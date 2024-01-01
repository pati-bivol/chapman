#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    translator = Translator();
}

FileProcessor::~FileProcessor() {}

void FileProcessor::processFile(string inputFile, string outputFile) {
    ofstream html;
    // opening the outputFile
    html.open(outputFile);
    html << "<!DOCTYPE html>" << endl;
    html << "<html>" << endl;
    html << "<head>" << endl;
    html << "<title>English to Robber Translation</title>" << endl;
    html << "</head>" << endl;
    html << "<body>" << endl;

    ifstream file(inputFile);
    string str;
    string temp;

// going throught the inputFile and adding the english sentences the outputFile in bold 
    while (getline(file, str)) {
        html << "<p><b>" << str << "</b><br></p>" << endl;
        // adding the robber language sentences to a temp varibale in italics 
        temp += "<p><i>" + translator.translateEnglishSentence(str) + "</i><br></p>\n";
    }
    html << "<p><b></b><br></p>" << endl;
    // adding the robber language sentences to the outputFile
    html << temp;
    html << "<p><i></i><br></p>";
    html << "</body>" <<  endl;
    html << "</html>" << endl;
    // closing the outputFile
    html.close();
}
