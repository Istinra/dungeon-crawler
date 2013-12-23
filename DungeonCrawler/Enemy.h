//
//  Enemy.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//
#ifndef __DungeonCrawler__Enemy__
#define __DungeonCrawler__Enemy__

#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy(Vector3 position, int textureId);

    virtual ~Enemy();

    virtual void Update();

protected:
    int textureId;
    const int originalId;
    int animationTimer;
};

#endif /* defined(__DungeonCrawler__Enemy__) */
