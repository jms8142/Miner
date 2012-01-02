#ifndef ENTITY_H
#define ENTITY_H
//
//  BaseGameEntitty.h
//  miner
//
//  Created by John Skrzypek on 12/16/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//

#include "Telegram.h"
#include "Locations.h"


class BaseGameEntity

{
private:
    int m_ID;
    location_type m_Location;
    
    static int m_iNextValidID;
    
    void SetID(int val);
    
public:
    
    BaseGameEntity(int id,location_type loc)
    {
        SetID(id);
        m_Location = loc;
    }
    
    virtual ~BaseGameEntity(){}
    
    virtual void Update()=0;
    
    
    virtual bool HandleMessage(const Telegram& msg)=0;
    
    int ID()const{return m_ID;}
    location_type Location()const{return m_Location;}
    void ChangeLocation(location_type loc) { m_Location=loc; }
    

};

#endif