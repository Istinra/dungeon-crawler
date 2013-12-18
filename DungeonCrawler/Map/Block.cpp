//
//  Block.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Block.h"

Block::Block(unsigned int id, int x, int y) : id(id), texX(x), texY(y)
{

}

Block::~Block()
{

}

bool Block::Use()
{
    return false;
}
