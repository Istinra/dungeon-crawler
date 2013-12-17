//
//  Entity.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <math.h>
#include "Entity.h"

Entity::Entity() : yaw(M_PI_2), sprite(nullptr)
{
    position.x = 142;
    position.y = 32;
    position.z = 416;
}

Entity::~Entity()
{
    if (sprite != nullptr)
    {
        delete sprite;
    }
}
