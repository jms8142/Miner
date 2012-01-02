#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
//#pragma warning (disable:4786)
//
//  EntityManager.h
//  miner
//
//  Created by John Skrzypek on 12/28/11.
//  Copyright 2011 One Eleven Interactive. All rights reserved.
//
#include <map>
#include <cassert>
#include <string>

class BaseGameEntity;

//provide easy access
#define EntityMgr EntityManager::Instance()


class EntityManager
{
private:
    
    typedef std::map<int, BaseGameEntity*> EntityMap;
        
    EntityMap   m_EntityMap;
    
    EntityManager(){}
    
    //copy ctor and assignment should be private
    EntityManager(const EntityManager&);
    EntityManager& operator=(const EntityManager&);
    
public:
    
    static EntityManager* Instance();
    
    void RegisterEntity(BaseGameEntity* NewEntity);
    
    BaseGameEntity* GetEntityFromID(int id)const;
    
    void RemoveEntity(BaseGameEntity* pEntity);
};


#endif