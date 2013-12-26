//
//  Pickup.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 26/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Pickup__
#define __DungeonCrawler__Pickup__

#include "Entity.h"

class Pickup : public Entity
{
public:
    Pickup(Vector3 const &position, Item item);

    virtual void Collide(Entity *e) override;


    virtual bool IsRemoved() override;

private:
    Item item;
    bool removed;
};

#endif /* defined(__DungeonCrawler__Pickup__) */
