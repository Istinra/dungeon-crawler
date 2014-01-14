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
#include "Map/Level.h"

Player::Player() : LivingEntity(Vector3(142, 32, 416)), battery(100), activeSlot(0)
{
}

Player::~Player()
{

}

void Player::Action()
{
    if (actionTimer > 0)
    {
        return;
    }
    actionTimer = 100;
    static const int checkDist = 96;
    std::vector<Entity *> potentialEntities;
    const std::vector<Entity *> &entities = level->Entities();
    for (Entity *entity : entities)
    {
        Vector3 entPos = entity->Position();
        if (entPos.x < position.x + checkDist && entPos.x > position.x - checkDist &&
                entPos.z < position.z + checkDist && entPos.z > position.z - checkDist)
        {
            if (entity == this) continue;
            potentialEntities.push_back(entity);
        }
    }

    float rSin = sinf(yaw);
    float rCos = cosf(yaw);

    for (int i = 0; i < checkDist; i += 4)
    {
        float x = position.x + rCos * i;
        float z = position.z - rSin * i;
        for (Entity *entity : potentialEntities)
        {
            if (entity->ContainsPoint(x, z))
            {
                entity->Use(this, inventory[activeSlot]);
                return;
            }
        }
        int xIndex = static_cast<int>(x / 64);
        int zIndex = static_cast<int>(z / 64);
        if ((*level)[xIndex + zIndex * level->Width()]->Use())
        {
            return;
        }
    }
}

void Player::Hurt(int damage)
{
    health -= damage;
}

bool Player::IsRemoved()
{
    return false;
}

void Player::Update()
{
    if (actionTimer > 0)
    {
        --actionTimer;
    }
}

void Player::GiveItem(Item item)
{
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        if (inventory[i].type == item.type)
        {
            inventory[i].count += item.count;
            break;
        }
        else if (inventory[i].count == 0)
        {
            inventory[i] = item;
            break;
        }
    }
}
