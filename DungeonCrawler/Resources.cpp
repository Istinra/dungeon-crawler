//
//  Resources.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 13/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Resources.h"
#include "External/std_image.h"


Resources::Resources()
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
        stbi_uc *string;
        string = stbi_load(file, &x, &y, &n, 0);
        bitmap = new Bitmap((unsigned int) x, (unsigned int) y, (unsigned int *) string);
        textures[texture] = bitmap;
    }
    else
    {
        return textures[texture];
    }
    return bitmap;
}
