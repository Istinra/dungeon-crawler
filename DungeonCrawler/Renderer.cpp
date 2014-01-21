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

#define SPRITE_SIZE 16

Renderer::Renderer() : pixels(new unsigned int[WIDTH * HEIGHT]), viewPort(HEIGHT - PANEL_HEIGHT, WIDTH, pixels, false),
symbols("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz%/\\.?")
{
    for(int i = 0; i < HEIGHT * WIDTH - PANEL_HEIGHT * WIDTH; i++)
    {
        pixels[i] = 0xFF0000;
    }
    Bitmap *const hudTexture = Resources::Instance().LoadTexture(HUD);
	int hudTextWidth = hudTexture->Width();
    unsigned int const *const hudPixels = hudTexture->Pixels();
    for (int h = HEIGHT - PANEL_HEIGHT, hudImgHeight = 0; h < HEIGHT; h++, hudImgHeight++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
			pixels[w + h * WIDTH] = hudPixels[w / 4 + hudImgHeight / 4 * hudTextWidth];
        }
    }
}

Renderer::~Renderer()
{
	delete [] pixels;
}

void Renderer::Draw(Game &game)
{
    if (game.GetPlayer().Alive())
    {
        viewPort.Draw(game);
        DrawText(NumberString(game.GetPlayer().Health()), 50, 390);
        DrawText(NumberString(game.GetPlayer().Battery()) + "%", 50, 425);
        DrawText(std::string("0/?"), 50, 455);
        DrawInventory(game);
    }
    else
    {
        DrawText(std::string("You died"), 320, 240);
    }
}


void Renderer::DrawText(const std::string text, int x, int y)
{
    Bitmap *const fontBitmap = Resources::Instance().LoadTexture(FONT);
	int fontBitmapWidth = fontBitmap->Width();
    unsigned int const *const fontPix = fontBitmap->Pixels();
    for (unsigned int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        const unsigned long location = symbols.find(c, 0);
        if (location != std::string::npos)
        {
			int heightOffset = (location / (fontBitmapWidth / LETTER_WIDTH)) * LETTER_HEIGHT;
			int widthOffset = (location % (fontBitmapWidth / LETTER_WIDTH)) * LETTER_WIDTH;
            for (int height = heightOffset, screenHeight = y; height < heightOffset + LETTER_HEIGHT; height++, screenHeight++)
            {
                for (int width = widthOffset, screenWidth = x; width < widthOffset + LETTER_WIDTH; width++, screenWidth++)
                {
                    pixels[screenWidth + screenHeight * WIDTH + i * LETTER_WIDTH] =
						fontPix[width + height * fontBitmapWidth];
                }
            }
        }
    }
}

void Renderer::DrawInventory(Game &game)
{
    const static float scale = 3.8f;
    Bitmap *const spriteBitmap = Resources::Instance().LoadTexture(ITEMS);
    unsigned int const *const spritePixels = spriteBitmap->Pixels();
	const int spriteBitmapWidth = spriteBitmap->Width();
    DrawHeldItem(game, spriteBitmap);
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        const Item item = game.GetPlayer().ItemAtSlot(i);
        if (item.count == 0)
        {
            return;
        }
		float heightOffset = static_cast<float>((item.type / (spriteBitmapWidth / SPRITE_SIZE)) * SPRITE_SIZE);
		float widthOffset = static_cast<float>((item.type % (spriteBitmapWidth / SPRITE_SIZE)) * SPRITE_SIZE);
        int screenHeight = 408;
        for (float height = heightOffset; height < heightOffset + SPRITE_SIZE; height += 1 / scale, screenHeight++)
        {
            int screenWidth = 120;
            for (float width = widthOffset; width < widthOffset + SPRITE_SIZE; width += 1 / scale, screenWidth++)
            {
                pixels[screenWidth + screenHeight * WIDTH + static_cast<int>(i * SPRITE_SIZE * (0.2f + scale))] =
					spritePixels[static_cast<int>(width) +static_cast<int>(height) * spriteBitmapWidth];
            }
        }
    }
}

void Renderer::DrawHeldItem(Game &game, Bitmap *const spriteBitmap)
{
    unsigned int const *const spritePixels = spriteBitmap->Pixels();
    const Item item = game.GetPlayer().ActiveItem();
    const static float scale = 10.0f;
	const int spriteBitmapWidth = spriteBitmap->Width();

    if (item.count == 0)
    {
        return;
    }
	float heightOffset = static_cast<float>((item.type / (spriteBitmapWidth / SPRITE_SIZE)) * SPRITE_SIZE);
	float widthOffset = static_cast<float>((item.type % (spriteBitmapWidth / SPRITE_SIZE)) * SPRITE_SIZE);
    heightOffset += game.GetPlayer().IsActing() ? 32 : 16;
    int screenHeight = 204;
    for (float height = heightOffset; height < heightOffset + SPRITE_SIZE; height += 1 / scale, screenHeight++)
    {
        int screenWidth = 384;
        for (float width = widthOffset; width < widthOffset + SPRITE_SIZE; width += 1 / scale, screenWidth++)
        {
            const unsigned int colour =
				spritePixels[static_cast<int>(width) +static_cast<int>(height) * spriteBitmapWidth];
            if (0xFF000000 & colour)
            {
                pixels[screenWidth + screenHeight * WIDTH] = colour;
            }
        }
    }
}

std::string Renderer::NumberString(int number)
{
	if (number < 10)
	{
		return std::string("0") + std::to_string(number);
	}
	return std::to_string(number);
}
