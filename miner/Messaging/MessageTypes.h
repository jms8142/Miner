//
//  MessageTypes.h
//  miner
//
//  Created by John Skrzypek on 12/28/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//
#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
    Msg_HiHoneyImHome,
    Msg_StewReady,
    Msg_ComingHome
};


inline std::string MsgToStr(int msg)
{
    switch (msg)
    {
        case Msg_HiHoneyImHome:
            
            return "HiHoneyImHome"; 
            
        case Msg_StewReady:
            
            return "StewReady";
            
        case Msg_ComingHome:
            
            return "Coming Home Kitty";
            
        default:
            
            return "Not recognized!";
    }
}

#endif