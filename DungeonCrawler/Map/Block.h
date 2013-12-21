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


    unsigned int Id()
    {
        return id;
    }

    int XTexture()
    {
        return texX;
    }

    int YTexture()
    {
        return texY;
    }

private:
    unsigned int id;
    int texX, texY;
};

#endif /* defined(__DungeonCrawler__Block__) */
