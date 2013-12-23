//
//  LivingEntity.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__LivingEntity__
#define __DungeonCrawler__LivingEntity__

#include "Entity.h"

class LivingEntity : public Entity
{

public:
    LivingEntity(Vector3 const &position);

    virtual ~LivingEntity();

    virtual void Hurt(int damage) = 0;

protected:
    short health;
    short damage;
};

#endif /* defined(__DungeonCrawler__LivingEntity__) */
