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

    Bitmap(unsigned int height, unsigned int width, unsigned int *data, bool cleanUp);

    virtual ~Bitmap();

    inline unsigned int const *Pixels()
    {
        return pixels;
    };

	inline int Height()
    {
        return height;
    };

    inline int Width()
    {
        return width;
    };
protected:
    const bool cleanUp;
    int height, width;
    unsigned int *pixels;
};

#endif
