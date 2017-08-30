//
//  Smoother.cpp
//  dda_with_vid_1
//
//  Created by Kento Morita on 2017/08/30.
//
//

#include "Smoother.hpp"

Smoother::Smoother() {
    
}

float Smoother::getSmoothedValue(float currentvalue, int _amount) {
    if (_amount <= 0) return;
    while (pvalues.size() > _amount) {
        pvalues.erase(pvalues.begin());
    }
    pvalues.push_back(currentvalue);
    
    float smooth = 0;
    for (int i=0; i<pvalues.size(); i++) {
        smooth += pvalues.at(i);
    }
    smooth /= pvalues.size();
    return smooth;
}
