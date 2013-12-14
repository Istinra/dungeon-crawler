//
//  RayCastBitmap.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <math.h>
#include "RayCastBitmap.h"
#include "Resources.h"

RayCastBitmap::RayCastBitmap(unsigned int height, unsigned int width):
Bitmap(height, width)
{
    //Row based, iterate last number in inner loop for caching
    //XZ Coordinate top down
    level[0][0] = 0;
    level[1][0] = 1;
    level[2][0] = 0;
    level[3][0] = 1;
    level[4][0] = 0;
    level[5][0] = 1;

    level[0][1] = 0;
    level[1][1] = 0;
    level[2][1] = 0;
    level[3][1] = 0;
    level[4][1] = 0;
    level[5][1] = 0;

    level[0][2] = 0;
    level[1][2] = 0;
    level[2][2] = 0;
    level[3][2] = 0;
    level[4][2] = 0;
    level[5][2] = 0;

    level[0][3] = 0;
    level[1][3] = 0;
    level[2][3] = 0;
    level[3][3] = 0;
    level[4][3] = 0;
    level[5][3] = 0;

    level[0][4] = 0;
    level[1][4] = 0;
    level[2][4] = 0; //Player
    level[3][4] = 0;
    level[4][4] = 0;
    level[5][4] = 0;

    posY = 32;
    posX = 191;
    posZ = 319;
    yaw = 1.57079633f;

    mapHeight = 5;
    mapWidth = 6;
}


void RayCastBitmap::Draw(Game &game)
{
    UpdatePosition(game);
    Bitmap *walls = Resources::instance().LoadTexture(WALLS);

    float angle = yaw + VIEWING_ANGLE / 2;
    for (int i = 0; i < width; i++, angle -= ANGLE_BETWEEN_RAYS)
    {
        float hX, hZ, vX, vZ;
        CheckHorizontalIntersections(angle, hX, hZ);
        CheckVerticalIntersections(angle, vX, vZ);

        float hDistance = sqrtf((posX - hX) * (posX - hX) + (posZ - hZ) * (posZ - hZ));
        float vDistance = sqrtf((posX - vX) * (posX - vX) + (posZ - vZ) * (posZ - vZ));

//        if (hDistance == INFINITY && INFINITY == vDistance)
//        {
//            continue;
//        }

        float distance;
        unsigned int texOffset;
        if (hDistance < vDistance)
        {
            distance = hDistance * cosf(angle - yaw);
            texOffset = static_cast<unsigned int>(hX) % GRID_SIZE;
        }
        else
        {
            distance = vDistance * cosf(angle - yaw);
            texOffset = static_cast<unsigned int>(vX) % GRID_SIZE;
        }
        int sliceHeight = static_cast<int>(GRID_SIZE / floorf(distance) * DISTANCE_TO_PLANE);
        int start = height / 2 - sliceHeight / 2;
        int end = height / 2 + sliceHeight / 2;
        if (start < 0)
        {
            start = 0;
        }
        if (end > height)
        {
            end = height - 1;
        }
        for(int h = 0; h < start; h++)
        {
            pixels[i + h * width] = 0x444444;
        }
        float texIncrement = 16.0f / (end - start);
        texOffset /= 4;
        for (float texPos = 0; start < end; start++, texPos += texIncrement)
        {
            unsigned int heightOffset = static_cast<unsigned int>(texPos) * walls->Width();
            pixels[i + start * width] = walls->Pixels()[heightOffset + texOffset];
        }
        for(int h = end; h < height; h++)
        {
            pixels[i + h * width] = 0x222222;
        }
    }
}

void RayCastBitmap::CheckHorizontalIntersections(const float angle, float &x, float &z)
{
    float aZ = floorf(posZ / GRID_SIZE) * GRID_SIZE + (angle > M_PI ? +GRID_SIZE : -1);
    float aX = posX + (posZ - aZ) / tanf(angle);

    int zIndex = static_cast<int>(aZ / GRID_SIZE);
    int xIndex = static_cast<int>(aX / GRID_SIZE);

    float zA = angle > M_PI ? +GRID_SIZE : -GRID_SIZE;
    float xA = GRID_SIZE / tanf(angle);

    while (zIndex < mapHeight && xIndex < mapWidth && aZ >= 0 && aX >= 0)
    {
        if (level[xIndex][zIndex] > 0)
        {
            x = aX;
            z = aZ;
            return;
        }
        aZ += zA;
        aX += xA;
        zIndex = static_cast<int>(aZ / GRID_SIZE);
        xIndex = static_cast<int>(aX / GRID_SIZE);
    }
    x = INFINITY;
    z = INFINITY;
}

void RayCastBitmap::CheckVerticalIntersections(const float angle, float &x, float &z)
{
    float aX = floorf(posX / GRID_SIZE) * GRID_SIZE + (angle < M_PI_2 || angle > M_PI_2 + M_PI ? +GRID_SIZE : -1);
    float aZ = posZ + (posX - aX) * tanf(angle);

    int zIndex = static_cast<int>(aZ / GRID_SIZE);
    int xIndex = static_cast<int>(aX / GRID_SIZE);

    float xA = angle < M_PI_2 || angle > M_PI_2 + M_PI ? GRID_SIZE : -GRID_SIZE;
    float zA = GRID_SIZE * (posX - aX > 0 ? tanf(angle) : -tanf(angle));

    while (zIndex < mapHeight && xIndex < mapWidth && aZ >= 0 && aX >= 0)
    {
        if (level[xIndex][zIndex] > 0)
        {
            x = aX;
            z = aZ;
            return;
        }
        aZ += zA;
        aX += xA;
        zIndex = static_cast<int>(aZ / GRID_SIZE);
        xIndex = static_cast<int>(aX / GRID_SIZE);
    }
    x = INFINITY;
    z = INFINITY;
}

RayCastBitmap::~RayCastBitmap()
{
}

void RayCastBitmap::UpdatePosition(Game &game)
{
    Player player = game.GetPlayer();
    Vector3 pos = player.Position();
    posX = pos.x;
    posY = pos.y;
    posZ = pos.z;
    yaw = player.Yaw();
}
