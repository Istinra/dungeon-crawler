//
//  Renderer.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//
#include "Renderer.h"
#include "Resources.h"

#define LETTER_WIDTH 6
#define LETTER_HEIGHT 8

Renderer::Renderer() : viewPort(HEIGHT - PANEL_HEIGHT, WIDTH),
symbols("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz%/\\.?")
{
    for(int i = 0; i < HEIGHT * WIDTH - PANEL_HEIGHT * WIDTH; i++)
    {
        pixels[i] = 0xFF0000;
    }
    Bitmap *const hudTexture = Resources::Instance().LoadTexture(HUD);
    unsigned int const *const hudPixels = hudTexture->Pixels();
    for (int h = HEIGHT - PANEL_HEIGHT, hudImgHeight = 0; h < HEIGHT; h++, hudImgHeight++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            pixels[w + h * WIDTH] = hudPixels[w / 4 + hudImgHeight / 4 * hudTexture->Width()];
        }
    }
}

void Renderer::Draw(Game &game)
{
    memcpy(pixels, viewPort.Pixels(), static_cast<size_t>(viewPort.Width() * viewPort.Height() * sizeof(int)));
    viewPort.Draw(game);
//    DrawText(std::to_string(game.GetPlayer().Health()), 0, 0);
    DrawText(std::string("Heloooooo"), 0, 0);
}

void Renderer::DrawText(const std::string text, float x, float y)
{
    Bitmap *const fontBitmap = Resources::Instance().LoadTexture(FONT);
    unsigned int const *const fontPix = fontBitmap->Pixels();
    char const *const string = text.c_str();
    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        const unsigned long location = symbols.find(c, 0);
        if (location != std::string::npos)
        {
            int heightOffset = (location / (fontBitmap->Width() / LETTER_WIDTH)) * LETTER_HEIGHT;
            int widthOffset = (location % (fontBitmap->Width() / LETTER_WIDTH)) * LETTER_WIDTH;
            for (int height = heightOffset, screenHeight = 0; height < heightOffset + LETTER_HEIGHT; height++, screenHeight++)
            {
                for (int width = widthOffset, screenWidth = 10; width < widthOffset + LETTER_WIDTH; width++, screenWidth++)
                {
                    //TODO Stop letters drawing on top of eachother
                    pixels[screenWidth + screenHeight * WIDTH] = fontPix[width + height * fontBitmap->Width()];
                }
            }
        }
    }
}
