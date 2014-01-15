//
//  Level.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Level.h"
#include "../BatEnemy.h"
#include "../Resources.h"
#include "../Pickup.h"
#include "DoorBlock.h"
#include <algorithm>
#include <iostream>

Level::Level()
{

}

Level::~Level()
{
    for (Block *b : blocks)
    {
        delete b;
    }
    for (Entity *entity : entities)
    {
        delete entity;
    }
}

void Level::LoadLevel(std::string name)
{
    Bitmap *levelImage = Resources::Instance().LoadLevel(name);
    width = levelImage->Width();
    height = levelImage->Height();
    blocks.resize(static_cast<unsigned int>(width * height));

    for (int i = 0; i < width * height; i++)
    {
        unsigned int pixel = levelImage->Pixels()[i];
        int x = i % width;
        int y = i / height;
        blocks[i] = CreateBlock(x, y, pixel);
        CheckEntities(x, y, pixel);
        //R : Block Type
        //G : Entity on the block
        //B : Pickup/Item entities
        //A : Block ID
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << std::hex << blocks[i * width + j]->Id() << " ";
        }
        std::cout << std::endl;
    }

    delete levelImage;
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

void Level::CheckEntities(int x, int y, unsigned pixel)
{
    Vector3 pos = Vector3(x * 64 + 32, 0, y * 62 - 32);
    switch (pixel)
    {
        case 0xFF00A000:
        {
            BatEnemy *bat = new BatEnemy(pos, 1);
            bat->SetSprite(new Sprite(0, 0, 0, 1));
            bat->SetLevel(this);
            entities.push_back(bat);
            break;
        }
        case 0xFF0000FF:
        {
            Pickup *pickup = new Pickup(pos, Item(1, POTION));
            pickup->SetSprite(new Sprite(0, 0, 0, 4));
            pickup->SetLevel(this);
            entities.push_back(pickup);
            break;
        }
        case 0xFF0000AA:
        {
            Pickup *pickup = new Pickup(pos, Item(1, SWORD));
            pickup->SetSprite(new Sprite(0, 0, 0, 4));
            pickup->SetLevel(this);
            entities.push_back(pickup);
            break;
        }
    }

}

Block *Level::CreateBlock(int x, int y, unsigned pixel)
{
    Block *block;
    switch (pixel)
    {
        case 0xFFFF0000:
            block = new DoorBlock(1, x, y, 2);
            break;
        case 0xFFFFFFFF:
            block = new Block(1, x, y, 0);
            break;
        default:
            block = new Block(0, x, y, 0);
    }
    return block;
}

void Level::Update()
{
    for (auto i = entities.begin(); i != entities.end(); i++)
    {
        (*i)->Update();
        if ((*i)->IsRemoved())
        {
            delete (*i);
            entities.erase(i);
        }
    }
}
