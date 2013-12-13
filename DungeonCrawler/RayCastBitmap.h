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

#define GRID_SIZE 64

#include "Bitmap.h"
#include "Game.h"

class RayCastBitmap : public Bitmap
{
public:
    RayCastBitmap(unsigned int height, unsigned int width);

    ~RayCastBitmap();

    void Draw(Game &game);

private:
    void UpdatePosition(Game &game);

    void CheckHorizontalIntersections(const float angle, float &x, float &z);
    void CheckVerticalIntersections(const float angle, float &x, float &z);

    int level[6][5];
    int mapWidth, mapHeight;
    float posX, posY, posZ, yaw;
};

#endif
