//
//  Graphics.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Bitmap_h
#define DungeonCrawler_Bitmap_h

class Bitmap {
public:
    Bitmap(unsigned height, unsigned width);

    virtual ~Bitmap();

    unsigned const *Pixels() {
        return pixels;
    };

    unsigned Height() {
        return height;
    };

    unsigned Width() {
        return width;
    };
protected:
    unsigned height, width;
    unsigned *pixels;
};

#endif
