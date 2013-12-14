//
//  Entity.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Entity.h"

Entity::Entity() : yaw(1.57079633f)
{
    position.x = 191;
    position.y = 32;
    position.z = 319;
}

Entity::~Entity()
{

}
