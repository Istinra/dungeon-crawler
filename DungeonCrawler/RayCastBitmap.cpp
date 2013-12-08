//
//  RayCastBitmap.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <math.h>
#include "RayCastBitmap.h"

RayCastBitmap::RayCastBitmap(unsigned int height, unsigned int width):
Bitmap(height, width)
{
    //Row based, iterate last number in inner loop for caching
    //XZ Coordinate top down

    // XXXX
    //    X
    //    X
    // O
    level[0][0] = 1;
    level[0][1] = 1;
    level[0][2] = 1;
    level[0][3] = 1;

    level[1][0] = 0;
    level[1][1] = 0;
    level[1][2] = 0;
    level[1][3] = 1;

    level[2][0] = 0;
    level[2][1] = 0;
    level[2][2] = 0;
    level[2][3] = 1;

    level[3][0] = 0; //Player Cube
    level[3][1] = 0;
    level[3][2] = 0;
    level[3][3] = 0;

    posY = 32;
    posX = 32;
    posZ = 224;
    yaw = 0.785398163f;

    mapHeight = 4;
    mapWidth = 4;
}

void RayCastBitmap::Draw(Game const game)
{
    float angle = yaw - VIEWING_ANGLE / 2;

    for (int i = 0; i < WIDTH; i++)
    {
        float vX, vZ;
        CheckHorizontalIntersections(angle, vX, vZ);


        angle += ANGLE_BETWEEN_RAYS;
    }
}

void RayCastBitmap::CheckHorizontalIntersections(float angle, float &x, float &z)
{
    float aZ = static_cast<int>(posZ / 64) * 64 + (angle > M_PI ? +64 : -1);
    float aX = (posZ - aZ) / tanf(angle);

    int zIndex = static_cast<int>(aZ) >> 8, xIndex = static_cast<int>(aX) >> 8;

    while (zIndex < height && xIndex < width &&
            zIndex > -1 && xIndex > -1)
    {
        if (level[zIndex][xIndex] > 0)
        {
            x = aX;
            z = aZ;
            return;
        }
        aZ += angle > M_PI ? +64 : -1;
        aX += 64 / tanf(angle);
        zIndex = static_cast<int>(aZ) >> 8;
        xIndex = static_cast<int>(aX) >> 8;
    }
    x = -1;
    z = -1;
}
