//
//  Graphics.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Bitmap.h"

Bitmap::Bitmap(unsigned int height, unsigned int width) : height(height), width(width), cleanUp(true)
{
    pixels = new int unsigned [height * width];
}

Bitmap::~Bitmap()
{
    if (cleanUp)
    {
        delete [] pixels;
    }
}

Bitmap::Bitmap(unsigned int height, unsigned int width, unsigned int *data, bool cleanUp) :
height(height), width(width), pixels(data), cleanUp(cleanUp)
{
}
