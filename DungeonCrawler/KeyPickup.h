//
//  Pickup.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 26/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__KeyPickup__
#define __DungeonCrawler__KeyPickup__

#include "Entity.h"

class KeyPickup : public Entity
{
public:
	KeyPickup(Vector3 const &position);

	virtual void Collide(Entity *e) override;

	virtual bool IsRemoved() override;

private:
	bool removed;
};

#endif /* defined(__DungeonCrawler__Pickup__) */
