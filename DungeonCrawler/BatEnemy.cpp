//
//  BatEnemy.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "BatEnemy.h"

BatEnemy::BatEnemy(Vector3 position, int textureId):Enemy(position, textureId)
{
    this->health = 5;
}