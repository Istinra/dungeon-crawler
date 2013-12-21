//
//  Player.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <vector>
#include <math.h>
#include "Player.h"
#include "Level.h"

Player::Player() : health(10), battery(100), activeSlot(0)
{

}

Player::~Player()
{

}

void Player::Action()
{
    float fromX = position.x;
    float fromZ = position.z;

    float toX = position.x + yaw > M_PI_2 * 3 || yaw < M_PI_2 ? 64 : -64;
    float toZ = position.z + yaw > M_PI ? -64 : 64;

    std::vector<Entity *> potentialEntities;
    const std::vector<Entity *> &entities = level->Entities();
    for (Entity *entity : entities)
    {
        Vector3 entPos = entity->position;
        if (entPos.x < position.x + 64 && entPos.x > position.x - 64 &&
                entPos.z < position.z + 64 && entPos.z > position.z - 64)
        {
            if (entity == this) continue;
            potentialEntities.push_back(entity);
        }
    }

    float rSin = sinf(yaw);
    float rCos = cosf(yaw);
    static const int maxCheckDistance = 64;

    for (int i = 0; i < maxCheckDistance; i += 4)
    {
        float x = position.x + rCos * i;
        float z = position.z + rSin * i;
        for (Entity *entity : potentialEntities)
        {
            if (entity->ContainsPoint(x, z))
            {
                entity->Use();
                return;
            }
        }
    }
}
