//
//  Resources.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 13/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Resources_h
#define DungeonCrawler_Resources_h

#include <map>
#include "Bitmap.h"

enum Textures
{
    WALLS,
    ROOF_FLOOR,
    HUD,
    SPRITES
};

class Resources
{
public:
    Resources();

    ~Resources();

    static Resources instance()
    {
        static Resources instance;
        return instance;
    };

    Bitmap *LoadTexture(Textures texture);

private:
    Bitmap *InitTexture(Textures texture, const char *file);

    std::map<Textures, Bitmap *> textures;
};

#endif
