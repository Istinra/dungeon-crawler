//
//  Block.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Block__
#define __DungeonCrawler__Block__

#include "CommonTypes.h"

class Block
{
public:
    Block()
    {
    }

    Block(unsigned int id, int x, int y);

    virtual ~Block();

    bool IsSolid();

    virtual bool Use();

    virtual bool CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const;

    unsigned int Id()
    {
        return id;
    }

private:
    unsigned int id;
};

#endif /* defined(__DungeonCrawler__Block__) */
