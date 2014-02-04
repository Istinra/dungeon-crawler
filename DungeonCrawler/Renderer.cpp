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

Renderer::Renderer() :
	pixels(new unsigned int[WIDTH * HEIGHT]),
	scaledHudGraphic(new unsigned int[PANEL_HEIGHT * WIDTH]),
	viewPort(HEIGHT - PANEL_HEIGHT, WIDTH, pixels, false),
	symbols("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz%/\\.?")
{
	Bitmap *const hudTexture = Resources::Instance().LoadTexture(HUD);
	int hudTextWidth = hudTexture->Width();
	unsigned int const *const hudPixels = hudTexture->Pixels();
	for (int h = 0, hudImgHeight = 0; h < PANEL_HEIGHT; h++, hudImgHeight++)
	{
		for (int w = 0; w < WIDTH; w++)
		{
			scaledHudGraphic[w + h * WIDTH] = hudPixels[w / 4 + hudImgHeight / 4 * hudTextWidth];
		}
	}
}

Renderer::~Renderer()
{
	delete [] pixels;
	delete [] scaledHudGraphic;
}

void Renderer::Draw(Game &game)
{
	if (game.GetPlayer().Alive())
	{
		viewPort.Draw(game);
		memcpy(pixels + WIDTH * (HEIGHT - PANEL_HEIGHT), scaledHudGraphic, sizeof(unsigned int) * PANEL_HEIGHT * WIDTH);
		DrawText(NumberString(game.GetPlayer().Health()), 50, 385, 2);
		DrawText(NumberString(game.GetPlayer().Battery()) + "%", 50, 420, 2);
		DrawText(std::string("0/?"), 50, 450, 2);
		DrawInventory(game);
		DrawSelectedItem(game);
	}
	else
	{
		DrawText(std::string("You died"), 120, 140, 8);
	}
}


void Renderer::DrawText(const std::string text, int x, int y, float scale)
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
			int letterOffset = static_cast<int>(i * LETTER_WIDTH * scale);
			int heightOffset = (location / (fontBitmapWidth / LETTER_WIDTH)) * LETTER_HEIGHT;
			int widthOffset = (location % (fontBitmapWidth / LETTER_WIDTH)) * LETTER_WIDTH;

			int endHeight = heightOffset + LETTER_HEIGHT;
			int endWidth = widthOffset + LETTER_WIDTH;

			float heightInc = LETTER_HEIGHT / (LETTER_HEIGHT * scale);
			float widthInc = LETTER_WIDTH / (LETTER_WIDTH * scale);

			float fHeight = static_cast<float>(heightOffset);
			for (int screenHeight = y; fHeight < endHeight; fHeight += heightInc, screenHeight++)
			{
				float fWidth = static_cast<float>(widthOffset);
				for (int screenWidth = x; fWidth < endWidth; fWidth += widthInc, screenWidth++)
				{
					unsigned int colour = fontPix[static_cast<int>(fWidth) +static_cast<int>(fHeight) * fontBitmapWidth];
					if (colour & 0xFF000000)
					{
						pixels[screenWidth + screenHeight * WIDTH + letterOffset] = colour;
					}
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

void Renderer::DrawSelectedItem(Game & game)
{
	Item item = game.GetPlayer().ActiveItem();
	switch (item.type)
	{
	case GUN:
		DrawText(std::string("Laser Gun"), 120, 370, 2);
		break;
	case SWORD:
		DrawText(std::string("Sword"), 120, 370, 2);
		break;
	case POTION:
		DrawText(std::string("Potion"), 120, 370, 2);
		break;
	default:
		break;
	}
}
