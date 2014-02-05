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

    void GiveItem(Item item);

    virtual void Hurt(int damage);

    virtual void Update() override;

    virtual bool IsRemoved() override;

    inline short Battery()
    {
        return battery;
    }

	inline bool Alive()
    {
        return health > 0;
    }

	inline Item ItemAtSlot(int slot)
    {
        return inventory[slot];
    }

	inline Item ActiveItem()
    {
        return inventory[activeSlot];
    }

	inline void ActiveItem(short activeSlot)
	{
		this->activeSlot = activeSlot;
	}

	inline bool IsActing()
    {
        return actionTimer > 0;
    }

	inline short Keys() 
	{ 
		return keys; 
	}

private:
	void Interact(int checkDistance);

    short battery;
	short keys;
    short actionTimer;

    Item inventory[MAX_INVENTORY];
    short activeSlot;
};

#endif
