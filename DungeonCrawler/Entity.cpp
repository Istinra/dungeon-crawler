//
//  Entity.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Entity.h"

Entity::Entity() : yaw(4.71238899), sprite(nullptr)
{
    position.x = 350;
    position.y = 32;
    position.z = 90;
}

Entity::~Entity()
{
    if (sprite != nullptr)
    {
        delete sprite;
    }
}
