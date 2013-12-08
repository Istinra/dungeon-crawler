//
//  Renderer.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Renderer.h"

Renderer::Renderer()
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

void Renderer::Draw(const Game &game)
{

}
