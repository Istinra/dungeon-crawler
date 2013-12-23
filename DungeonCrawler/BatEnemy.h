//
//  BatEnemy.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 23/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__BatEnemy__
#define __DungeonCrawler__BatEnemy__

#include "Enemy.h"

class BatEnemy : public Enemy
{

public:
    BatEnemy(Vector3 position, int textureId);

private:
    int health;
};

#endif /* defined(__DungeonCrawler__BatEnemy__) */
