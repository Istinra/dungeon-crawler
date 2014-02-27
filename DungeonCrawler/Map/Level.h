//
//  Level.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Level__
#define __DungeonCrawler__Level__

#include <string>
#include <vector>
#include "../Entity.h"
#include "TriggerBlock.h"
#include "Block.h"

class Player;

class Level
{
public:
    Level();
    virtual ~Level();

    void LoadLevel(std::string name);
    void AddEntity(Entity *entity);
	void AddPlayer(Player *player);
    void RemoveEntity(Entity *entity);
	void SortEntitiesByDistToPlayer();
    void Update();

    inline Block *operator [] (unsigned int i) const
	{
		return blocks[i];
	}

	inline const int Width() const
    {
        return width;
    }

	inline const int Height() const
    {
        return height;
    }

    std::vector<Entity *> const &Entities() const
    {
        return entities;
    };

	inline const unsigned int Colour() const
	{
		return colour;
	}

	inline const Player * const GetPlayer() const
	{
		return player;
	}

private:
	Block *CreateBlock(int x, int y, unsigned pixel, std::vector<TriggerBlock*>& triggerBlocks);

    void CreateEntities(int x, int y, unsigned pixel);

    int width, height;
	unsigned int colour;
	Player *player;
    std::vector<Block *> blocks;
    std::vector<Entity *> entities;
	std::vector<Entity *> entityQueue;
};

#endif /* defined(__DungeonCrawler__Level__) */
