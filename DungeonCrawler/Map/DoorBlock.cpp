//
//  DoorBlock.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 28/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "DoorBlock.h"

DoorBlock::DoorBlock(unsigned int id, int x, int y, unsigned int tex):Block(id, x, y, tex), closed(true)
{
}

bool DoorBlock::CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const
{
    if (closed)
    {
        x += xDiff / 2;
        z += zDiff / 2;
        return true;
    }
    return false;
}

bool DoorBlock::Use()
{
    if (closed)
    {
        closed = false;
        return true;
    }
    return false;
}

bool DoorBlock::IsSolid() const
{
    return closed;
}
