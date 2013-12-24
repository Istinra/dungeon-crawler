//
//  Renderer.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <string.h>
#include "Renderer.h"
#include "Resources.h"

Renderer::Renderer() : viewPort(HEIGHT - PANEL_HEIGHT, WIDTH)
{
    for(int i = 0; i < HEIGHT * WIDTH - PANEL_HEIGHT * WIDTH; i++)
    {
        pixels[i] = 0xFF0000;
    }
    Bitmap *const hudTexture = Resources::instance().LoadTexture(HUD);
    unsigned int const *const hudPixels = hudTexture->Pixels();
    for (int h = HEIGHT - PANEL_HEIGHT, hudImgHeight = 0; h < HEIGHT; h++, hudImgHeight++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            pixels[w + h * WIDTH] = hudPixels[w / 4 + hudImgHeight / 4 * hudTexture->Width()];
        }
    }
}

void Renderer::Draw(Game &game) {
    memcpy(pixels, viewPort.Pixels(), static_cast<size_t>(viewPort.Width() * viewPort.Height() * sizeof(int)));
    //Note UI frame doesn't need to be redrawn
    viewPort.Draw(game);
}
