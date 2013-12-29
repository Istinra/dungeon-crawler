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

    Block(unsigned int id, int x, int y, unsigned int tex);

    virtual ~Block();

    virtual bool IsSolid() const;

    virtual bool Use();

    virtual bool CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const;

    unsigned int Id() const
    {
        return id;
    }

    unsigned int Texture() const
    {
        return tex;
    }

private:
    const unsigned int id;
    const unsigned int tex;
};

#endif /* defined(__DungeonCrawler__Block__) */
