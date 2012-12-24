//
//  CrudeTimer.cpp
//  miner
//
//  Created by John Skrzypek on 12/29/11.
//

#include "CrudeTimer.h"


CrudeTimer* CrudeTimer::Instance()
{
    static CrudeTimer instance;
    
    return &instance;
}