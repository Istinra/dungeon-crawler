//
//  Block.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Block.h"

Block::Block(unsigned int id, int x, int y) : id(id)
{

}

Block::~Block()
{

}

bool Block::Use()
{
    if (id << 8 == 0)
    {
        return false;
    }
    id = 0;
    return true;
}

bool Block::IsSolid()
{
    return id << 8 > 0;
}

bool Block::CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const
{
    return id << 8 != 0;
}
