//
//  VineEntity.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 02/03/2014.
//  Copyright (c) 2014 Sam. All rights reserved.
//
#ifndef __DungeonCrawler__VineEntity__
#define __DungeonCrawler__VineEntity__

#include "Entity.h"

class VineEntity : public Entity
{
public:
	VineEntity(Vector3 position, int xIndex, int zIndex);
	virtual ~VineEntity();

	virtual bool Use(Entity *source, Item &item) override;

private:
	int xIndex;
	int zIndex;
};

#endif