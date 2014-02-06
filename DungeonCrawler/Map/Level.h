//
//  Level.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Level__
#define __DungeonCrawler__Level__

#include <string>
#include <vector>
#include "../Entity.h"
#include "TriggerBlock.h"
#include "Block.h"

class Level
{
public:
    Level();
    virtual ~Level();

    void LoadLevel(std::string name);
    void AddEntity(Entity *entity);
    void RemoveEntity(Entity *entity);

    void Update();

    inline Block *operator [] (unsigned int i) const
	{
		return blocks[i];
	}

    int Width() const
    {
        return width;
    }

    int Height() const
    {
        return height;
    }

    std::vector<Entity *> const &Entities() const
    {
        return entities;
    };

private:
	Block *CreateBlock(int x, int y, unsigned pixel, std::vector<TriggerBlock*>& triggerBlocks);

    void CheckEntities(int x, int y, unsigned pixel);

    int width, height;
    std::vector<Block *> blocks;
    std::vector<Entity *> entities;
};

#endif /* defined(__DungeonCrawler__Level__) */
