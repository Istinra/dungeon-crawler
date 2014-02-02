//
//  DoorBlock.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 28/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Block.h"

#ifndef __DungeonCrawler__DoorBlock__
#define __DungeonCrawler__DoorBlock__

class DoorBlock : public  Block
{

public:
    DoorBlock(unsigned int id, int x, int y, unsigned int tex);

	virtual bool Use(Item& item) override;

    virtual bool IsSolid() const override;

    virtual bool CheckSolidAndAdjust(float xDiff, float zDiff, float &x, float &z) const override;

private:
    bool closed;
};

#endif /* defined(__DungeonCrawler__DoorBlock__) */
