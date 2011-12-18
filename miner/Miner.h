//
//  Miner.h
//  miner
//
//  Created by John Skrzypek on 12/16/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//

class Miner : public BaseGameEntity
{
private:
    State*  m_pCurrentState;
    location_type   m_Location;
    int     m_iGoldCarried;
    int     m_iMoneyInBank;
    int     m_iThirst;
    int     m_iFatigue;
    
public:
    
    Miner(int ID);
    
    void Update();
    
    voidde ChangeState(State* pNewState);
    
    void ChangeState(State* pNewState);
    
}


