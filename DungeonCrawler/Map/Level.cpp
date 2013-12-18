//
//  Level.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Level.h"
#include "Resources.h"
#include <iostream>

Level::Level() : blocks(nullptr)
{

}

Level::~Level()
{
    if (blocks != nullptr)
    {
        delete [] blocks;
    }
    for (Entity *entity : entities)
    {
        delete entity;
    }
}

void Level::LoadLevel(std::string name)
{
    Bitmap *levelImage = Resources::instance().LoadLevel(name);
    width = levelImage->Width();
    height = levelImage->Height();
    blocks = new Block[width * height];

    for (int i = 0; i < width * height; i++)
    {
        blocks[i] = Block(levelImage->Pixels()[i], i % width, i / height);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::hex << blocks[i * width + j].Id() << " ";
        }
        std::cout << std::endl;
    }

    delete levelImage;
}

Block &Level::operator [](unsigned int i)
{
    return blocks[i];
}

void Level::AddEntity(Entity *entity)
{
    entities.push_back(entity);
    entity->SetLevel(this);
}

void Level::RemoveEntity(Entity *entity)
{
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
}
