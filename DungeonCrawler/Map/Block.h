//
//  Block.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Block__
#define __DungeonCrawler__Block__

#include "../Common/CommonTypes.h"
#include "../Item.h"
#include "../Entity.h"

class Block
{
public:

    Block(unsigned int id, int x, int y, unsigned int tex);

    virtual ~Block();

    virtual bool IsSolid() const;

	virtual bool IsCollidable() const
	{
		return collidable;
	}

	void Collidable(bool collidable)
	{
		this->collidable = collidable;
	}

	virtual bool Use(Entity* source, const Item& item);

    virtual bool CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const;

    unsigned int Id() const
    {
        return id;
    }

    unsigned int Texture() const
    {
        return tex;
    }

	virtual bool Trigger(const Item& item);

protected:
    const unsigned int id;
    unsigned int tex;
	bool collidable;
};

#endif /* defined(__DungeonCrawler__Block__) */
