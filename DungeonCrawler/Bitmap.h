//
//  Graphics.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Bitmap_h
#define DungeonCrawler_Bitmap_h

class Bitmap
{
public:
    Bitmap(unsigned height, unsigned width);
    ~Bitmap();
private:
    unsigned height, width;
    unsigned *pixels;
};

#endif
