#ifndef CAT_H
#define CAT_H
//
//  cat.cpp
//  miner
//
//  Created by John Skrzypek on 1/2/12.
//  Copyright 2012 One Eleven Interactive. All rights reserved.
//

#include "State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "CatOwnedStates.h"
#include "StateMachine.h"

using std::cout;
const int HungerThreshold = 5;

class Cat : public BaseGameEntity
{
private:
    StateMachine<Cat>* m_pStateMachine;
    
    //location_type   m_Location;
    int             m_iHungry;
    
public:
    Cat(int id):m_iHungry(0),
    BaseGameEntity(id,shack)
    {
        m_pStateMachine = new StateMachine<Cat>(this);
        m_pStateMachine->SetCurrentState(Sleep::Instance());
        
    }
    
    ~Cat(){delete m_pStateMachine;}
    
    void Update();
    
    virtual bool HandleMessage(const Telegram& msg);
    
    StateMachine<Cat>* GetFSM()const{return m_pStateMachine;}
    
    //location_type Location()const{return m_Location;}
   // void    ChangeLocation(location_type loc){m_Location=loc;}
    void    IncreaseHunger(){m_iHungry += 1;}
    void    DecreaseHunger(){m_iHungry = 0;
        //cout << "Hunger is now " << m_iHungry;
    }
    bool    Hungry()const;
};

#endif