//
//  CrudeTimer.cpp
//  miner
//
//  Created by John Skrzypek on 12/29/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//

#include "CrudeTimer.h"


CrudeTimer* CrudeTimer::Instance()
{
    static CrudeTimer instance;
    
    return &instance;
}