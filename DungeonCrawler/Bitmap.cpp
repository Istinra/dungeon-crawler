//
//  Graphics.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "Bitmap.h"

Bitmap::Bitmap(unsigned height, unsigned width) : height(height), width(width)
{
    pixels = new unsigned[height * width];
}

Bitmap::~Bitmap()
{
    delete [] pixels;
}

Bitmap::Bitmap(unsigned height, unsigned width, unsigned int *data) : height(height), width(width), pixels(data)
{
}
