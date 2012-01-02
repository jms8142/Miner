#ifndef MESSAGE_DISPATCHER_H
#define MESSAGE_DISPATCHER_H
//#pragma warning (disable:4786)
//
//  MessageDispatcher.h
//  miner
//
//  Created by John Skrzypek on 12/28/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//
#include <set>

#include "Telegram.h"

class BaseGameEntity;


//to make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0;
const int    NO_ADDITIONAL_INFO   = 0;

#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
    
    //a std::set is used as the container for the delayed messages
    //because of the benefit of automatic sorting and avoidance
    //of duplicates. Messages are sorted by their dispatch time.
    std::set<Telegram> PriorityQ;
    
    //this method is utilized by DispatchMsg or DispatchDelayedMessages.
    //This method calls the message handling member function of the receiving
    //entity, pReceiver, with the newly created telegram
    void Discharge(BaseGameEntity* pReceiver,const Telegram& msg);
    
    MessageDispatcher(){}
    
    //copy ctor and assignment should be private
    MessageDispatcher(const MessageDispatcher&);
    MessageDispatcher& operator=(const MessageDispatcher&);
    
public:
    
    static MessageDispatcher* Instance();

    void DispatchMessage(double delay,
                         int    sender,
                         int    receiver,
                         int    msg,
                         void*  ExtraInfo);
    
    void DispatchDelayedMessages();
};


#endif