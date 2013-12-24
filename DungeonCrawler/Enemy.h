//
//  Enemy.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//
#ifndef __DungeonCrawler__Enemy__
#define __DungeonCrawler__Enemy__

#include "LivingEntity.h"

class Enemy : public LivingEntity
{
public:
    Enemy(Vector3 position, int textureId);
    virtual ~Enemy();

    virtual void Update();

    virtual void Collide(Entity *e);

    virtual void Hurt(int damage);

    virtual bool Use(Entity *source, Item &item);

protected:
    const int textureId;
    int attackCoolDown;
    int animationTimer;
};

#endif /* defined(__DungeonCrawler__Enemy__) */
