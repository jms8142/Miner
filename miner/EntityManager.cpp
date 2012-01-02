//
//  EntityManager.cpp
//  miner
//
//  Created by John Skrzypek on 12/28/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//

#include "EntityManager.h"
#include "BaseGameEntity.h"

using std::cout;

EntityManager* EntityManager::Instance()
{
    static EntityManager instance;
    
    return &instance;
}

BaseGameEntity* EntityManager::GetEntityFromID(int id)const
{
    //cout << "\nGetEntityFromID with " << id << "\n";
    EntityMap::const_iterator ent = m_EntityMap.find(id);
    
    assert( (ent != m_EntityMap.end()) && "<Entity Manager::GetEntityFromID>: invalid ID");
    
    return ent->second;
}

void EntityManager::RemoveEntity(BaseGameEntity *pEntity)
{
    m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}

void EntityManager::RegisterEntity(BaseGameEntity *NewEntity)
{
    //cout << "Registered Entity with ID " << NewEntity->ID() << "\n";
    m_EntityMap.insert(std::make_pair(NewEntity->ID(),NewEntity));
}
