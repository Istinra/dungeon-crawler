//
//  DoorBlock.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 28/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "DoorBlock.h"
#include "../Player.h"
#include "../NotificationManager.h"

DoorBlock::DoorBlock(unsigned int id, int x, int y, unsigned int tex, DoorBlockState state) 
: Block(id, x, y, tex), state(state)
{
}

bool DoorBlock::CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const
{
    if (state != OPEN)
    {
        x += xDiff / 2;
        z += zDiff / 2;
        return true;
    }
    return false;
}

bool DoorBlock::Use(Entity* source, const Item& item)
{
	switch (state)
	{
	case OPEN:
		return false;
	case TRIGGERED:
		NotificationManager::Instance().PostNotification("This door is opened elsewhere", 350);
		break;
	case CLOSED:
		state = OPEN;
		break;
	case LOCKED:
	{
		Player* player = dynamic_cast<Player*>(source);
		if (player && !player->UseKey())
		{
			NotificationManager::Instance().PostNotification("This door requires a key", 350);
		}
		else
		{
			state = OPEN;
		}
		break;
	}
	case BROKEN:
	{
		NotificationManager::Instance().PostNotification("This door appears to be broken", 350);
		break;
	}
	}
	return true;
}

bool DoorBlock::Trigger(const Item& item)
{
	if (TRIGGERED)
	{
		state = OPEN;
		return true;
	}
	return false;
}

bool DoorBlock::IsSolid() const
{
    return state != OPEN;
}

bool DoorBlock::IsCollidable() const
{
	return IsSolid();
}
