//
//  Enemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

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
    Entity::Update();
    sprite->texNumber = textureId + (++animationTimer % 200 > 100 ? 1 : 0);
    if (attackCoolDown > 0)
    {
        --attackCoolDown;
    }
}

void Enemy::Collide(Entity *e)
{
    Player *player = dynamic_cast<Player *>(e);
    if (player)
    {
        player->Hurt(damage);
    }
}

void Enemy::Hurt(int damage)
{

}
