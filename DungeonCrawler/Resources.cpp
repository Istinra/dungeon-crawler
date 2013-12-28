//
//  Resources.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <string>
#include "Resources.h"
#include "External/std_image.h"


Resources::Resources() : levelDirectory("/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/")
{

}

Resources::~Resources()
{
    for (auto val : textures)
    {
        delete val.second;
    }
}

Bitmap *Resources::LoadTexture(Textures texture)
{
    Bitmap *bitmap = nullptr;

    switch (texture)
    {
        case WALLS:
            bitmap = InitTexture(texture, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/walls.png");
            break;
        case SPRITES:
            bitmap = InitTexture(texture, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/sprites.png");
            break;
        case HUD:
            bitmap = InitTexture(texture, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/HUD.png");
            break;
        case FONT:
            bitmap = InitTexture(texture, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/font.png");
            break;
        case ITEMS:
            bitmap = InitTexture(texture, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/items.png");
            break;
        default:
            break;
    }
    return bitmap;
}

Bitmap *Resources::InitTexture(Textures texture, const char *file)
{
    Bitmap *bitmap;
    if (textures.find(texture) == textures.end())
    {
        int x, y, n;
        stbi_uc *string = stbi_load(file, &x, &y, &n, 0);
        stbi_uc *p = string;
        for (int i = 0; i < x * y; ++i)
        {
            unsigned char t = p[0];
            p[0] = p[2];
            p[2] = t;
            p += 4;
        }
        bitmap = new Bitmap((unsigned int) y, (unsigned int) x, (unsigned int *) string);
        textures[texture] = bitmap;
    }
    else
    {
        return textures[texture];
    }
    return bitmap;
}

Bitmap *Resources::LoadLevel(std::string name)
{
    std::string s = levelDirectory + name + ".png";
    int x, y, n;
    stbi_uc *string = stbi_load(s.c_str(), &x, &y, &n, 0);
    stbi_uc *p = string;
    for (int i = 0; i < x * y; ++i)
    {
        unsigned char t = p[0];
        p[0] = p[2];
        p[2] = t;
        p += 4;
    }
    return new Bitmap((unsigned int) y, (unsigned int) x, (unsigned int *) string);
}
