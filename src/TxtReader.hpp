//
//  TxtReader.hpp
//  dda_with_vid_1
//
//  Created by Kento Morita on 2017/08/30.
//
//

#pragma once

#include "ofMain.h"

class TxtReader {
public:
    TxtReader();
    vector<string> readFile(string source, string delimiter = " ");
    void startData() {startMillis = ofGetElapsedTimeMillis();};
    string readCurrentData();
    void printValues();
private:
    int startMillis = 0;
    int valPerFrame = 28;
    vector<string> values;
};
