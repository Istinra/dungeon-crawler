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
#include "Entity.h"
#include "Block.h"

class Level
{
public:
    Level();
    virtual ~Level();

    void LoadLevel(std::string name);
    void AddEntity(Entity *entity);

    void RemoveEntity(Entity *entity);

    Block &operator [] (unsigned int);

    int Width()
    {
        return width;
    }

    int Height()
    {
        return height;
    }

    std::vector<Entity *> &Entities()
    {
        return entities;
    };

private:
    Block *CreateBlock(int x, int y, unsigned pixel);

    void CheckEntities(int x, int y, unsigned pixel);

    int width, height;
    std::vector<Block *> blocks;
    std::vector<Entity *> entities;
};

#endif /* defined(__DungeonCrawler__Level__) */
