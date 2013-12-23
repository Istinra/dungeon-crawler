//
//  Enemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Enemy.h"


Enemy::Enemy(Vector3 position, int textureId) : Entity(position), textureId(textureId), animationTimer(0)
{

}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
    Entity::Update();
    sprite->texNumber = textureId + (++animationTimer % 200 > 100 ? 1 : 0);
}
