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
#include "../VineEntity.h"
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
	roofColour = pixels[1];
	floorColour = pixels[2];
	blocks[0] = CreateBlock(0, 0, 0xFFFFFFFF, triggerBlocks);
	blocks[1] = CreateBlock(0, 0, 0xFFFFFFFF, triggerBlocks);
	blocks[2] = CreateBlock(0, 0, 0xFFFFFFFF, triggerBlocks);

	for (int i = 3; i < width * height; i++)
	{
		unsigned int pixel = pixels[i];
		int x = i % width;
		int y = i / width;
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
	entityQueue.push_back(entity);
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
	Vector3 pos = Vector3(x * 64.0f + 32.0f, 0.0f, y * 64.0f + 32.0f);
	switch (pixel)
	{
	case 0xFF00A000:
	{
					   BatEnemy *bat = new BatEnemy(pos, 1);
					   bat->SetSprite(new Sprite(0, 0, 0, 1));
					   AddEntity(bat);
					   break;
	}
	case 0xFF00B000:
	{
					   BatEnemy *bat = new BatEnemy(pos, 16);
					   bat->SetSprite(new Sprite(0, 0, 0, 16));
					   bat->SetHealth(12);
					   AddEntity(bat);
					   break;
	}
	case 0xFF005600:
	{
					   SkeletonEnemy *skele = new SkeletonEnemy(pos, 8);
					   skele->SetSprite(new Sprite(0, 0, 0, 8));
					   AddEntity(skele);
					   break;
	}
	case 0xFF005000:
	{
					   SkeletonEnemy *skele = new SkeletonEnemy(pos, 18);
					   skele->SetSprite(new Sprite(0, 0, 0, 18));
					   skele->SetHealth(12);
					   AddEntity(skele);
					   break;
	}
	case 0xFF0000FF:
	{
					   Pickup *pickup = new Pickup(pos, Item(1, POTION));
					   pickup->SetSprite(new Sprite(0, 0, 0, 4));
					   AddEntity(pickup);
					   break;
	}
	case 0xFF0000AA:
	{
					   Pickup *pickup = new Pickup(pos, Item(1, SWORD));
					   pickup->SetSprite(new Sprite(0, 0, 0, 4));
					   AddEntity(pickup);
					   break;
	}
	case 0xFF000066:
	{
					   Pickup *pickup = new Pickup(pos, Item(1, GUN));
					   pickup->SetSprite(new Sprite(0, 0, 0, 4));
					   AddEntity(pickup);
					   break;
	}
	case 0xFF000088:
	{
					   KeyPickup *pickup = new KeyPickup(pos);
					   pickup->SetSprite(new Sprite(0, 0, 0, 5, 0x00000000, 0.5f));
					   AddEntity(pickup);
					   break;
	}
	case 0xFFC60000:
	{
					   VineEntity *vine = new VineEntity(pos, x, y);
					   vine->SetSprite(new Sprite(0, 0, 0, 14, 0x00000000, 1));
					   AddEntity(vine);
					   break;
	}
	default:
	{
			   if ((pixel & 0x00FFFF00) == 0x00FEFE00)
			   {
				   Ladder* ladder = new Ladder(pos, std::string("l") + std::to_string(0xFF & pixel));
				   ladder->SetSprite(new Sprite(0, 0, 0, (pixel & 0xFF000000) == 0xFF000000 ? 6 : 7));
				   AddEntity(ladder);
				   break;
			   }
	}
	}

}

Block *Level::CreateBlock(int x, int y, unsigned pixel, std::vector<TriggerBlock*>& triggerBlocks)
{
	int id = (pixel & 0xFF000000) >> 24;
	if ((pixel & 0x00FFFFF0) == 0x00FF0000)
	{
		//Blue channel to enum
		DoorBlockState state = static_cast<DoorBlockState>(pixel & 0x000000FF);
		unsigned int texId;
		switch (state)
		{
		case LOCKED:
			texId = 7;
			break;
		case BROKEN:
			texId = 6;
			break;
		default:
			texId = 3;
			break;
		}
		return new DoorBlock(id, x, y, texId, state);
	}
	else if ((pixel & 0x00FF00FF) == 0x00630000)
	{
		//Green Channel used to identify target block ID
		TriggerBlock* trigger = new TriggerBlock(id, x, y, 1);
		trigger->TargetId((pixel & 0x0000FF00) >> 8);
		triggerBlocks.push_back(trigger);
		return trigger;
	}
	else if (pixel == 0xFF800000)
	{
		return new IceBlock(id, x, y, 4);
	}
	else if (pixel == 0xFFC60000)
	{
		Block* b = new Block(0, x, y, 0);
		b->Collidable(true);
		return b;
	}
	else if ((pixel & 0x00FFFFFF) == 0x00FFFFFF)
	{
		unsigned int texId = pixel >> 24;
		return new Block(id, x, y, texId == 255 ? 0 : texId);
	}
	return new Block(0, x, y, 0);
}

void Level::Update()
{
	for (auto i = entities.begin(); i != entities.end();)
	{
		(*i)->Update();
		if ((*i)->IsRemoved())
		{
			delete (*i);
			entities.erase(i);
		}
		else
		{
			i++;
		}
	}
	entities.insert(entities.end(), entityQueue.begin(), entityQueue.end());
	entityQueue.clear();
}

void Level::SortEntitiesByDistToPlayer()
{
	if (entities.size() == 0)
	{
		return;
	}
	float *distanceCache = new float[entities.size()];
	Vector3 playerPos = player->Position();
	for (int i = 0; i < entities.size(); i++)
	{
		Vector3 pos = entities[i]->Position();
		distanceCache[i] = hypotf(playerPos.x - pos.x, playerPos.z - pos.z);
	}

	//Quicksort is too much effort for a list of max 20~ items
	Entity* tempEnt;
	float tempDist;
	bool finalPass = true;

	for (int i = 1; finalPass; i++)
	{
		finalPass = false;
		for (int j = 0; j < entities.size() - i; j++)
		{
			if (distanceCache[j] < distanceCache[j + 1])
			{
				tempEnt = entities[j];
				tempDist = distanceCache[j];
				entities[j] = entities[j + 1];
				distanceCache[j] = distanceCache[j + 1];
				entities[j + 1] = tempEnt;
				distanceCache[j + 1] = tempDist;
				finalPass = true;
			}
		}
	}
	delete distanceCache;
}

void Level::GiveEnergy(short energy)
{
	player->GiveEnergy(energy);
}

