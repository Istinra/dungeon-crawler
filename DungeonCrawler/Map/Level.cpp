//
//  Level.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Level.h"
#include "Resources.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::LoadLevel(std::string name)
{
    Bitmap *levelImage = Resources::instance().LoadLevel(name);

    delete levelImage;
}
