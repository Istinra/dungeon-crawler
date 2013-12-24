//
//  Enemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy(Vector3 position, int textureId) : LivingEntity(position),
textureId(textureId), animationTimer(0), attackCoolDown(0)
{

}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
    sprite->texNumber = textureId + (++animationTimer % 200 > 100 ? 1 : 0);
    if (attackCoolDown > 0)
    {
        --attackCoolDown;
    }
    //Only step movement every 30 frames
    if (animationTimer % 200 == 0)
    {
        yaw += static_cast<float>((rand() % 360) * 180 / M_PI) * TURN_STEP;
        if (yaw < 0)
        {
            yaw += 2 * M_PI;
        }
        else if (yaw > 2 * M_PI )
        {
            yaw -= 2 * M_PI;
        }
    }
    Move(Vector3(MOVE_STEP * cosf(yaw), 0, MOVE_STEP * sinf(yaw)));
}

void Enemy::Collide(Entity *e)
{
    if (!attackCoolDown)
    {
        attackCoolDown = 100;
        Player *player = dynamic_cast<Player *>(e);
        if (player)
        {
            player->Hurt(damage);
        }
    }
}

void Enemy::Hurt(int damage)
{
    health -= damage;
}

bool Enemy::Use(Entity *source, Item &item)
{
    Hurt(2);
    return true;
}
