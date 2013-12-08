//
//  RayCastBitmap.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_RayCastBitmap_h
#define DungeonCrawler_RayCastBitmap_h

#include "Bitmap.h"

class RayCastBitmap : public Bitmap
{
public:

private:
public:
    RayCastBitmap(unsigned int height, unsigned int width);

    float posX, posY, posZ, yaw;
};

#endif
