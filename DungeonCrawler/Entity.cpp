//
//  Entity.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <math.h>
#include "Entity.h"
#include "Level.h"

const float Entity::boundingWidth = 20.0f;

Entity::Entity(Vector3 position) : yaw(M_PI_2), sprite(nullptr), position(position)
{
}

Entity::~Entity()
{
    if (sprite != nullptr)
    {
        delete sprite;
    }
}

void Entity::Move(Vector3 movement)
{
    //Check if the there is a collision 
    float bound = movement.x < 0 ? -boundingWidth : boundingWidth;
    int xBox = static_cast<int>((position.x + movement.x + bound) / 64.0f);
    int zBox = static_cast<int>((position.z + movement.z) / 64.0f);
    Block &xBlock = (*level)[xBox + level->Width() * zBox];
    if (xBlock.IsSolid())
    {
        movement.x = 0.0f;
    }
    bound = movement.z < 0 ? -boundingWidth : boundingWidth;
    xBox = static_cast<int>((position.x + movement.x) / 64.0f);
    zBox = static_cast<int>((position.z + movement.z + bound) / 64.0f);
    Block &zBlock = (*level)[xBox + level->Width() * zBox];
    if (zBlock.IsSolid())
    {
        movement.z = 0.0f;
    }
    position = position + movement;
}

void Entity::SetLevel(Level *level)
{
    this->level = level;
}

bool Entity::ContainsPoint(float x, float z)
{
    return x < position.x + 40 && x > position.x - 40 &&
            z < position.z + 40 && z > position.z - 40;
}

bool Entity::Use()
{
    return false;
}

void Entity::Update()
{

}

void Entity::Collide(Entity *e)
{

}
