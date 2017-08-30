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
    started = false;
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

void TxtReader::startData() {
    if (started) return;
    startMillis = ofGetElapsedTimeMillis();
    started = true;
}

void TxtReader::endData() {
    startMillis = -100000;
}

string TxtReader::readCurrentData() {
    if (!started) return "0";
    if (values.size() == 0) return "0";
    int rownum = floor(float(ofGetElapsedTimeMillis() - startMillis) / float(valPerFrame));
    cout << "rownum: " << rownum << endl;
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
