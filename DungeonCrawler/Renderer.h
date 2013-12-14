//
//  Renderer.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Renderer_h
#define DungeonCrawler_Renderer_h

#define PANEL_HEIGHT 100

#include "Game.h"
#include "RayCastBitmap.h"

class Renderer
{
public:
    Renderer();

    void Draw(Game &game);

    unsigned int *Pixels()
    {
        return pixels;
    }

private:
    unsigned int pixels[WIDTH * HEIGHT];
    RayCastBitmap viewPort;
};

#endif
