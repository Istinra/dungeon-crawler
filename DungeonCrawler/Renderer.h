//
//  Renderer.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Renderer_h
#define DungeonCrawler_Renderer_h

#define PANEL_HEIGHT 29 * 4

#include "Game.h"
#include "RayCastBitmap.h"
#include <string.h>

class Renderer
{
public:
    Renderer();

    void Draw(Game &game);

    void DrawText(const std::string text, int x, int y);

    void DrawInventory(Game &game);

    unsigned int *Pixels()
    {
        return pixels;
    }

private:
    const std::string symbols;
    unsigned int pixels[WIDTH * HEIGHT];
    RayCastBitmap viewPort;

    void DrawHeldItem(Game &game, Bitmap *const spriteBitmap);
};

#endif
