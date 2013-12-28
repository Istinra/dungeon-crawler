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
    SWORD = 0,
    POTION = 1
};

struct Item
{
    Item() : count(0)
    {
    }

    Item(int count, ItemType const &type):count(count), type(type)
    {
    }

    int count;
    ItemType type;
};

#endif /* defined(__DungeonCrawler__Item__) */
