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

	~Renderer();

    void Draw(Game &game);

    void DrawText(const std::string text, int x, int y, float scale);

    void DrawInventory(Game &game);

    unsigned int *Pixels()
    {
        return pixels;
    }

private:
	std::string NumberString(int number);
	void DrawHeldItem(Game &game, const Bitmap *const spriteBitmap);
	void DrawSelectedItem(Game & game);

    const std::string symbols;
    unsigned int *pixels;
	unsigned int *scaledHudGraphic;
    RayCastBitmap viewPort;
};

#endif
