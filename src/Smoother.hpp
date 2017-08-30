//
//  Smoother.hpp
//  dda_with_vid_1
//
//  Created by Kento Morita on 2017/08/30.
//
//

#pragma once

#include "ofMain.h"

class Smoother {
public:
    Smoother();
    
    float getSmoothedValue(float currentvalue, int _amount);
private:
    vector<float> pvalues;
};
