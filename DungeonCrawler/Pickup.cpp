//
//  Pickup.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 26/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Pickup.h"
#include "Player.h"

Pickup::Pickup(Vector3 const &position, Item item):Entity(position), item(item)
{
}

void Pickup::Collide(Entity *e)
{
    Player *player = dynamic_cast<Player *>(e);
    if (player)
    {
        player->GiveItem(item);
    }
}
