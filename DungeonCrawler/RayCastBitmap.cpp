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

    for (int i = 0; i < width; i++)
    {
        float hX, hZ, vX, vZ;
        CheckHorizontalIntersections(angle, hX, hZ);
        CheckVerticalIntersections(angle, vX, vZ);

        float hDistance = fabsf(posX - hX) / cosf(angle);
        float vDistance = fabsf(posX - vX) / cosf(angle);

        if (hDistance == INFINITY && INFINITY == vDistance) continue;

        float distance;
        if (hDistance < vDistance)
        {
            distance = hDistance * cosf(angle);
        }
        else
        {
            distance = vDistance * cosf(angle);
        }
        int sliceHeight = 64 / static_cast<int>(distance) * DISTANCE_TO_PLANE;
        int start = height / 2 - sliceHeight / 2;
        int end = height / 2 + sliceHeight / 2;
        if (start < 0) start = 0;
        if (end > height) end = height - 1;
        for (; start < end; start++)
        {
            pixels[i + start * width] = 0x00FF00;
        }

        angle += ANGLE_BETWEEN_RAYS;
    }
}

void RayCastBitmap::CheckHorizontalIntersections(const float angle, float &x, float &z)
{
    float aZ = floorf(posZ / 64) * 64 + (angle > M_PI ? +64 : -1);
    float aX = posX + (posZ - aZ) / tanf(angle); //o / t

    int zIndex = static_cast<int>(aZ) / 64,
            xIndex = static_cast<int>(aX) / 64;

    float zA = angle > M_PI ? +64 : -64;
    float xA = 64 / tanf(angle);

    while (zIndex < height && xIndex < width &&
            zIndex > -1 && xIndex > -1)
    {
        if (level[zIndex][xIndex] > 0)
        {
            x = aX;
            z = aZ;
            return;
        }
        aZ += zA;
        aX += xA;
        zIndex = static_cast<int>(aZ) / 64;
        xIndex = static_cast<int>(aX) / 64;
    }
    x = INFINITY;
    z = INFINITY;
}

void RayCastBitmap::CheckVerticalIntersections(const float angle, float &x, float &z)
{
    float aX = floorf(posX / 64) * 64 + (angle < M_PI_2 || angle > M_PI_2 + M_PI ? +64 : -1);
    float aZ = posZ + (posX - aX) * tanf(angle);

    int zIndex = static_cast<int>(aZ) / 64,
            xIndex = static_cast<int>(aX) / 64;

    float xA = angle < M_PI_2 || angle > M_PI_2 + M_PI ? +64 : -64;
    float zA = 64 * tanf(angle);

    while (zIndex < height && xIndex < width &&
            zIndex > -1 && xIndex > -1)
    {
        if (level[zIndex][xIndex] > 0)
        {
            x = aX;
            z = aZ;
            return;
        }
        aZ += zA;
        aX += xA;
        zIndex = static_cast<int>(aZ) / 64;
        xIndex = static_cast<int>(aX) / 64;
    }
    x = INFINITY;
    z = INFINITY;
}
