//
//  Player.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//
#ifndef DungeonCrawler_Player_h
#define DungeonCrawler_Player_h

#define MAX_INVENTORY 8

#include "LivingEntity.h"
#include "Item.h"

class Player : public LivingEntity
{
public:
    Player();

    virtual ~Player();

    void Action();

    virtual void Hurt(int damage);

    virtual void Update() override;

    virtual bool IsRemoved() override;

    short Battery()
    {
        return battery;
    }

private:
    short battery;
    short actionTimer;

    Item inventory[MAX_INVENTORY];
    short activeSlot;
};

#endif
