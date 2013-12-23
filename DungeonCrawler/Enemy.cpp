//
//  Enemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Enemy.h"


Enemy::Enemy(Vector3 position, int textureId) : Entity(position), textureId(textureId),
originalId(textureId), animationTimer(0)
{

}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
    Entity::Update();
    textureId = originalId + (++animationTimer % 100 == 0 ? 1 : 0);
}
