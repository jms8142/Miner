#ifndef CAT_OWNED_STATES_H
#define CAT_OWNED_STATES_H
//
//  CatOwnedStates.h
//  miner
//
//  Created by John Skrzypek on 1/2/12.
//
#include "State.h"

class Cat;

class Sleep : public State<Cat>
{
private:
    Sleep(){}
    Sleep(const Sleep&);
    Sleep& operator=(const Sleep&);
public:
    static Sleep* Instance();
    virtual void Enter(Cat* cat);
    virtual void Execute(Cat* cat);
    virtual void Exit(Cat* cat);
    virtual bool OnMessage(Cat* cat,const Telegram& msg);
};

//------------------------------------------------------------------------
//
//  cat will go home and eat at its bowl
//------------------------------------------------------------------------
class Eat : public State<Cat>
{
private:
    
    Eat(){}
    
    //copy ctor and assignment should be private
    Eat(const Eat&);
    Eat& operator=(const Eat&);
    
public:
    
    //this is a singleton
    static Eat* Instance();
    
    virtual void Enter(Cat* cat);
    
    virtual void Execute(Cat* cat);
    
    virtual void Exit(Cat* cat);
    
    virtual bool OnMessage(Cat* agent, const Telegram& msg);
};




#endif