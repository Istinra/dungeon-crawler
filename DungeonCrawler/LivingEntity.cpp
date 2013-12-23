//
//  LivingEntity.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "LivingEntity.h"

LivingEntity::LivingEntity(Vector3 const &position):Entity(position), health(10), damage(1)
{
}

LivingEntity::~LivingEntity()
{

}