#ifndef STATE_H
#define STATE_H
//
//  State.h
//  miner
//
//  Created by John Skrzypek on 12/20/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//
struct Telegram;

template <class entity_type>
class State
{
public:
    virtual ~State(){};
    virtual void Enter(entity_type*)=0;
    virtual void Execute(entity_type*)=0;
    virtual void Exit(entity_type*)=0;
    
    //this executes if the agent receives a message from the 
    //message dispatcher
    virtual bool OnMessage(entity_type*,const Telegram&)=0;
};

#endif