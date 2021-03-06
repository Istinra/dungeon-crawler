//
//  RayCastBitmap.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
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
    RayCastBitmap(unsigned int height, unsigned int width, unsigned int *data, bool cleanUp);

    ~RayCastBitmap();

    void Draw(Game &game);

private:
    void UpdatePosition(Game &game);

    void DrawWalls(Game &game);

    void DrawSprites(Game &game);

    void CheckHorizontalIntersections(Level &level, const float angle, float &x, float &z, unsigned int &tex);

    void CheckVerticalIntersections(Level &level, const float angle, float &x, float &z, unsigned int &tex);

    void CheckIntersections(Level &level, float aZ, float aX, float zA, float xA, float &x, float &z, unsigned int &tex);

    float CorrectAngle(float angle);

    float posX, posY, posZ, yaw;
    float zBuffer[WIDTH];
};

#endif
