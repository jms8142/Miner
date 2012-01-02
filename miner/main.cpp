#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "cat.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "EntityNames.h"

std::ofstream os;

int main()
{
    
#ifdef TEXTOUTPUT
    os.open("output.txt");
#endif
    
    //seed random number generator
    srand((unsigned) time(NULL));
    
    Miner* Bob = new Miner(ent_Miner_Bob);
    MinersWife* Elsa = new MinersWife(ent_Elsa);
    Cat* Kitty = new Cat(ent_Cat);
    
    
    EntityMgr->RegisterEntity(Bob);
    EntityMgr->RegisterEntity(Elsa);
    EntityMgr->RegisterEntity(Kitty);
    
    for(int i=0; i<30;++i){
        Bob->Update();
        Elsa->Update();
        Kitty->Update();
        Dispatch->DispatchDelayedMessages();
        
        
        usleep(500000);

    }
    
   
    delete Bob;
    delete Elsa;
    delete Kitty;
    
    return 0;
    
}