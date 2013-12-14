//
//  Level.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Level.h"
#include "Resources.h"

Level::Level() : blocks(nullptr)
{

}

Level::~Level()
{
    if (blocks != nullptr)
    {
        delete [] blocks;
    }
}

void Level::LoadLevel(std::string name)
{
    Bitmap *levelImage = Resources::instance().LoadLevel(name);
    width = levelImage->Width();
    height = levelImage->Width();
    blocks = new Block[width * height];

    for (int i = 0; i < width * height; i++)
    {
        blocks[i] = Block(levelImage->Pixels()[i], i % width, i / height);
    }

    delete levelImage;
}

Block &Level::operator [](unsigned int i)
{
    return blocks[i];
}
