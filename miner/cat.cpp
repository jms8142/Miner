#include "cat.h"

using std::cout;

bool Cat::HandleMessage(const Telegram& msg)
{
    return m_pStateMachine->HandleMessage(msg);
}


void Cat::Update()
{
    //set text color to green
    // SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    m_pStateMachine->Update();
}

bool Cat::Hungry()const
{
    
    //cout << "\n" <<m_iHungry << " : " << HungerThreshold;
    if(m_iHungry > HungerThreshold)
    {
       return true;
    }
    
    return false;
}