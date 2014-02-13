//
//  Pickup.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 26/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "KeyPickup.h"
#include "Player.h"

KeyPickup::KeyPickup(Vector3 const &position) :Entity(position), removed(false)
{
}

void KeyPickup::Collide(Entity *e)
{
	Player *player = dynamic_cast<Player *>(e);
	if (player && !removed)
	{
		player->GiveKey();
		removed = true;
	}
}

bool KeyPickup::IsRemoved()
{
	return removed;
}

KeyPickup::~KeyPickup()
{

}
