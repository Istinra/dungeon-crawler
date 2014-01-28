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

	std::vector<TriggerBlock*> triggerBlocks;
    for (int i = 0; i < width * height; i++)
    {
        unsigned int pixel = levelImage->Pixels()[i];
        int x = i % width;
        int y = i / height;
        blocks[i] = CreateBlock(x, y, pixel, triggerBlocks);
        CheckEntities(x, y, pixel);
        //R : Block Type
        //G : Entity on the block
        //B : Pickup/Item entities
        //A : Block ID
    }

	for (auto* trigger : triggerBlocks)
	{
		auto blockId = trigger->TargetId();
		for (auto* b : blocks)
		{
			if (b->Id() == blockId)
			{
				trigger->SetBlockToTrigger(b);
				break;
			}
		}
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
	Vector3 pos = Vector3(x * 64.0f + 32.0f, 0.0f, y * 62.0f - 32.0f);
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

Block *Level::CreateBlock(int x, int y, unsigned pixel, std::vector<TriggerBlock*>& triggerBlocks)
{
	int id = (pixel & 0xFF000000) >> 24;
	if ((pixel & 0x00FFFFFF) == 0x00FF0000)
	{
		return new DoorBlock(id, x, y, 2);
	}
	if ((pixel & 0x00FF00FF) == 0x00630000)
	{
		//Green Channel used to identify target block ID
		TriggerBlock* trigger = new TriggerBlock(id, x, y, 0);
		trigger->TargetId((pixel & 0x0000FF00) >> 8);
		triggerBlocks.push_back(trigger);
		return trigger;
	}
	if (pixel == 0xFFFFFFFF)
	{
		return new Block(id, x, y, 0);
	}
	return new Block(0, x, y, 0);;
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
