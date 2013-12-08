//
//  RayCastBitmap.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_RayCastBitmap_h
#define DungeonCrawler_RayCastBitmap_h

#define VIEWING_ANGLE 1.04719755f
#define DISTANCE_TO_PLANE 512
#define WIDTH 640
#define HEIGHT 480
#define ANGLE_BETWEEN_RAYS VIEWING_ANGLE / WIDTH


#include "Bitmap.h"
#include "Game.h"

class RayCastBitmap : public Bitmap
{
public:
    RayCastBitmap(unsigned int height, unsigned int width);

    void Draw(Game const game);

private:
    int level[4][4];
    int mapWidth, mapHeight;
    float posX, posY, posZ, yaw;

    void CheckHorizontalIntersections(const float angle, float &x, float &z);

    void CheckVerticalIntersections(const float angle, float &x, float &z);

};

#endif
