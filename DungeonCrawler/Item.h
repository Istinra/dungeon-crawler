//
//  Item.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 18/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Item__
#define __DungeonCrawler__Item__

enum ItemType
{
    POTION
};

class Item
{
public:
    Item();

    ~Item();

private:
    ItemType type;
};

#endif /* defined(__DungeonCrawler__Item__) */