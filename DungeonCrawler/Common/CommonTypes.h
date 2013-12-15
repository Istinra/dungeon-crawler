//
//  Vector.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Vector_h
#define DungeonCrawler_Vector_h

struct Sprite
{

    Sprite(float x, float y, float z, int texNumber):x(x), y(y), z(z), texNumber(texNumber)
    {
    }

    float x;
    float y;
    float z;
    int texNumber;
};

struct Vector3
{

    Vector3()
    {
    }

    Vector3(float x, float y, float z):x(x), y(y), z(z)
    {
    }

    float x;
    float y;
    float z;
};

#endif
