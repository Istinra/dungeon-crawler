//
//  Renderer.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <string.h>
#include "Renderer.h"

Renderer::Renderer() : viewPort(HEIGHT - PANEL_HEIGHT, WIDTH)
{
    for(int i = 0; i < HEIGHT * WIDTH - PANEL_HEIGHT * WIDTH; i++)
    {
        pixels[i] = 0xFF0000;
    }
    for(int i = HEIGHT * WIDTH - PANEL_HEIGHT * WIDTH; i < HEIGHT * WIDTH; i++)
    {
        pixels[i] = 0x0000FF;
    }
}

void Renderer::Draw(Game &game) {
    memcpy(pixels, viewPort.Pixels(), viewPort.Width() * viewPort.Height() * sizeof(unsigned int));
    //Note UI frame doesn't need to be redrawn
    viewPort.Draw(game);
}
