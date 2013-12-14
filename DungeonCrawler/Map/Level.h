//
//  Level.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Level__
#define __DungeonCrawler__Level__

#include <iostream>

class Level
{
    Level();

    virtual ~Level();

    void LoadLevel(std::string name);
};

#endif /* defined(__DungeonCrawler__Level__) */
