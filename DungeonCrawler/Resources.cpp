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
            if (textures.find(WALLS) == textures.end())
            {
                bitmap = InitTexture("/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/walls.png");
            }
            else
            {
                return textures[WALLS];
            }
            break;
        default:
            break;
    }
    return bitmap;
}

Bitmap *Resources::InitTexture(const char *file)
{
    Bitmap *bitmap;
    int x, y, n;
    stbi_uc *string;
    string = stbi_load(file, &x, &y, &n, 0);
    bitmap = new Bitmap((unsigned int) x, (unsigned int) y, (unsigned int *) string);
    textures[WALLS] = bitmap;
}
