//
//  TxtReader.cpp
//  dda_with_vid_1
//
//  Created by Kento Morita on 2017/08/30.
//
//

#include "TxtReader.hpp"

TxtReader::TxtReader() {
    
}

vector<string> TxtReader::readFile(string source, string delimiter) {
    values.clear();
    
    vector < string > linesOfTheFile;
    ofBuffer buffer = ofBufferFromFile(source);
    for (auto line : buffer.getLines()){
        linesOfTheFile.push_back(line);
    }
    
    values = ofSplitString(linesOfTheFile.at(0), delimiter);
    
//    values = ofSplitString(source, delimiter);
    return values;
}

string TxtReader::readCurrentData() {
    int rownum = floor(float(ofGetElapsedTimeMillis() - startMillis) / float(valPerFrame));
    if (rownum > values.size()-1) return "0";
    return values.at(rownum);
}

void TxtReader::printValues() {
    cout << ofGetFrameNum() << ": ";
    for (int i=0; i<values.size(); i++) {
        cout << values.at(i) << ", ";
    }
    cout << endl;
}
