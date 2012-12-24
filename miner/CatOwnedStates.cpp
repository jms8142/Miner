//
//  CatOwnedStates.cpp
//  miner
//
//  Created by John Skrzypek on 1/2/12.
//

#include "CatOwnedStates.h"
#include "cat.h"
#include "EntityNames.h"
#include "EntityManager.h"
#include "Locations.h"
#include "CrudeTimer.h"
#include "MessageTypes.h"

#include <iostream>
using std::cout;



//-------------------------------------------------Sleep

Sleep* Sleep::Instance()
{
    static Sleep instance;
    return &instance;
}

void Sleep::Enter(Cat* cat)
{
   cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Kitty going to sleep.";
}

void Sleep::Execute(Cat* cat)
{
    cat->IncreaseHunger();
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "zzzzz";
    
    if(cat->Hungry())
    {
        if(EntityMgr->GetEntityFromID(ent_Miner_Bob)->Location() != shack)
        {
            cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "I'm hungry and the coast is clear";
            cat->GetFSM()->ChangeState(Eat::Instance());
        } else {
            cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Too scared, gonna stay here";
        }

    }
    
    
   }

void Sleep::Exit(Cat* cat)
{
     cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "Waking up for food.";
}

bool Sleep::OnMessage(Cat* cat, const Telegram& msg)
{
    //send msg to global message handler
    return false;
}

//------------------------------------------------------------------------EatStew
Eat* Eat::Instance()
{
    static Eat instance;
    return &instance;
}

void Eat::Enter(Cat* cat)
{
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "coming out to eat!";
    cat->ChangeLocation(kitty_bowl);
    
}

void Eat::Execute(Cat* cat)
{
    //cout << "is cat hungry? " << cat->Hungry();
    
    if(!cat->Hungry())
    {
        cout << " Changing back to sleep";
        cat->GetFSM()->ChangeState(Sleep::Instance());
    }
    else 
    {
        cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "mmm wet food!";
        cat->DecreaseHunger();
    }
  
}

void Eat::Exit(Cat* cat)
{
    cout << "\n" << GetNameOfEntity(cat->ID()) << ": " << "done eating, time to sleep";
}

bool Eat::OnMessage(Cat* cat, const Telegram& msg)
{
    switch(msg.Msg)
    {
        case Msg_ComingHome:
        {
            cout << "\nMessage received by " << GetNameOfEntity(cat->ID()) <<
            " at time: " << Clock->GetCurrentTime();
            
            cout << "\n" << GetNameOfEntity(cat->ID()) << ": Oh crap, he's coming home!  I'm going back to sleep";
            
            cat->GetFSM()->ChangeState(Sleep::Instance());
        }
            
    }
    
    //send msg to global message handler
    return false;
}

