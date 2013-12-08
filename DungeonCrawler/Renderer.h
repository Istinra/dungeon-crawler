//
//  Renderer.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 7/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Renderer_h
#define DungeonCrawler_Renderer_h

#define WIDTH 640
#define HEIGHT 480
#define PANEL_HEIGHT 100

#include "Game.h"

class Renderer
{
public:
    Renderer();
    void Draw(const Game& game);
    unsigned *Pixels() { return pixels; }
private:
    unsigned pixels[WIDTH * HEIGHT];

};

#endif
