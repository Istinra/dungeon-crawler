//
//  Enemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Enemy.h"
#include "Player.h"

#define HURT_COLOUR 0x00FF0000
#define DEAD_TEXTURE 3

Enemy::Enemy(Vector3 position, int textureId) : LivingEntity(position),
textureId(textureId), animationTimer(0), attackCoolDown(0)
{
    colour = HURT_COLOUR;
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
    if (health < 1)
    {
        --animationTimer;
        return;
    }
    if (hurtTimer > 0)
    {
        --hurtTimer;
        if (hurtTimer == 0)
        {
            unsigned int temp = sprite->colour;
            sprite->colour = colour;
            colour = temp;
        }
    }
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
			yaw += static_cast<float>(M_PI) * 2.0f;
        }
        else if (yaw > 2 * M_PI )
        {
			yaw -= static_cast<float>(M_PI) * 2.0f;
        }
    }
    Move(Vector3(MOVE_STEP * cosf(yaw), 0, MOVE_STEP * sinf(yaw)));
}

void Enemy::Collide(Entity *e)
{
    if (!attackCoolDown)
    {
        attackCoolDown = 150;
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
    if (health > 0)
    {
        unsigned int temp = sprite->colour;
        sprite->colour = colour;
        colour = temp;
        hurtTimer = 100;
    }
    else
    {
        sprite->texNumber = DEAD_TEXTURE;
        animationTimer = 100;
    }
}

bool Enemy::Use(Entity *source, Item &item)
{
	if (source != this)
	{
		if (item.type == ItemType::SWORD)
		{
			Hurt(3);
			return true;
		}
		if (item.type == ItemType::GUN)
		{
			Hurt(2);
			return true;
		}
	}
	return false;
}

bool Enemy::IsRemoved()
{
    return health < 1 && animationTimer < 1;
}
