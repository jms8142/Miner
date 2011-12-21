#ifndef STATE_H
#define STATE_H
//
//  State.h
//  miner
//
//  Created by John Skrzypek on 12/20/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//
class Miner;

class State
{
public:
    virtual ~State(){}
    
    virtual void Enter(Miner*)=0;
    virtual void Execute(Miner*)=0;
    virtual void Exit(Miner*)=0;
};

#endif