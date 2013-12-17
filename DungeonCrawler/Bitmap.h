//
//  Graphics.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Bitmap_h
#define DungeonCrawler_Bitmap_h

class Bitmap
{
public:
    Bitmap(unsigned int height, unsigned int width);

    Bitmap(unsigned int height, unsigned int width, unsigned int *data);

    virtual ~Bitmap();

    unsigned int const *Pixels()
    {
        return pixels;
    };

    int Height()
    {
        return height;
    };

    int Width()
    {
        return width;
    };
protected:
    int height, width;
    unsigned int *pixels;
};

#endif
