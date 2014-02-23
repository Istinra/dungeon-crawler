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
#include "../SkeletonEnemy.h"
#include "../KeyPickup.h"
#include "../Ladder.h"
#include "../Player.h"
#include "DoorBlock.h"
#include "IceBlock.h"
#include <algorithm>
#include <iostream>

Level::Level() : player(nullptr)
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
    const Bitmap *levelImage = Resources::Instance().LoadLevel(name);
    width = levelImage->Width();
    height = levelImage->Height();
    blocks.resize(static_cast<unsigned int>(width * height));

	std::vector<TriggerBlock*> triggerBlocks;
	const unsigned int * pixels = levelImage->Pixels();
	colour = pixels[0];
	blocks[0] = CreateBlock(0, 0, 0xFFFFFFFF, triggerBlocks);

    for (int i = 1; i < width * height; i++)
    {
		unsigned int pixel = pixels[i];
        int x = i % width;
        int y = i / height;
        blocks[i] = CreateBlock(x, y, pixel, triggerBlocks);
		CreateEntities(x, y, pixel);
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

void Level::AddPlayer(Player *entity)
{
	player = entity;
	AddEntity(player);
}

void Level::RemoveEntity(Entity *entity)
{
	if (entity == player)
	{
		player = nullptr;
	}
    entities.erase(std::remove(entities.begin(), entities.end(), entity));
}

void Level::CreateEntities(int x, int y, unsigned pixel)
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
		case 0xFF005600:
		{
			SkeletonEnemy *skele = new SkeletonEnemy(pos, 8);
			skele->SetSprite(new Sprite(0, 0, 0, 8));
			skele->SetLevel(this);
			entities.push_back(skele);
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
		case 0xFF000066:
		{
			Pickup *pickup = new Pickup(pos, Item(1, GUN));
			pickup->SetSprite(new Sprite(0, 0, 0, 4));
			pickup->SetLevel(this);
			entities.push_back(pickup);
			break;
		}
		case 0xFF000088:
		{
			KeyPickup *pickup = new KeyPickup(pos);
			pickup->SetSprite(new Sprite(0, 0, 0, 5, 0x00000000, 0.5f));
			pickup->SetLevel(this);
			entities.push_back(pickup);
			break;
		}
		default:
		{
			if ((pixel & 0x00FFFF00) == 0x00FEFE00)
			{
				Ladder* ladder = new Ladder(pos, std::string("l") + std::to_string(0xFF & pixel));
				entities.push_back(ladder); //pixel & 0x000000FF
				ladder->SetSprite(new Sprite(0, 0, 0, (pixel & 0xFF000000) == 0xFF000000 ? 6 : 7));
				ladder->SetLevel(this);
				break;
			}
		}
    }

}

Block *Level::CreateBlock(int x, int y, unsigned pixel, std::vector<TriggerBlock*>& triggerBlocks)
{
	int id = (pixel & 0xFF000000) >> 24;
	if ((pixel & 0x00FFFFFF) == 0x00FF0000)
	{
		return new DoorBlock(id, x, y, 3, static_cast<DoorBlockState>(pixel & 0x000000FF));
	}
	if ((pixel & 0x00FF00FF) == 0x00630000)
	{
		//Green Channel used to identify target block ID
		TriggerBlock* trigger = new TriggerBlock(id, x, y, 1);
		trigger->TargetId((pixel & 0x0000FF00) >> 8);
		triggerBlocks.push_back(trigger);
		return trigger;
	}
	if (pixel == 0xFF800000)
	{
		return new IceBlock(id, x, y, 4);
	}
	if ((pixel & 0x00FFFFFF) == 0x00FFFFFF)
	{
		unsigned int texId = pixel >> 24;
		return new Block(id, x, y, texId == 255 ? 0 : texId);
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
			--i;
        }
    }
}
