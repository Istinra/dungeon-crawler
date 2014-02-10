//
//  IceBlock.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 28/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Block.h"

#ifndef __DungeonCrawler__IceBlock__
#define __DungeonCrawler__IceBlock__

class IceBlock : public  Block
{

public:
	IceBlock(unsigned int id, int x, int y, unsigned int tex);

	virtual bool Use(Entity* source, const Item& item) override;

	virtual bool IsSolid() const override;

private:
	bool closed;
};

#endif /* defined(__DungeonCrawler__IceBlock__) */
