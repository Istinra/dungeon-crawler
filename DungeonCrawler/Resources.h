//
//  Resources.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Resources_h
#define DungeonCrawler_Resources_h

#include <map>
#include <string>
#include "Bitmap.h"
#include "Sound.h"

enum Textures
{
    WALLS,
    FONT,
    HUD,
    SPRITES,
    ITEMS
};

class Resources
{
public:
    Resources();

    ~Resources();

    static Resources &Instance()
    {
        static Resources instance;
        return instance;
    };

    Bitmap const *LoadTexture(Textures texture);

    Bitmap const *LoadLevel(std::string name);

private:
    Bitmap *InitTexture(Textures texture, const char *file);

    const std::string levelDirectory;
    std::map<Textures, Bitmap *> textures;
};

#endif
