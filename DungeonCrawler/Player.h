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

#include "Entity.h"
#include "Item.h"

class Player : public Entity
{
public:
    Player();
    ~Player();

    void Action();

private:
    short health;
    short battery;

    Item inventory[MAX_INVENTORY];
    short activeSlot;
};

#endif
