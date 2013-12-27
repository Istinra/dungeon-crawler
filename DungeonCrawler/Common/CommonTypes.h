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
    Sprite(float x, float y, float z, int texNumber, unsigned int colour):
    x(x), y(y), z(z), texNumber(texNumber), colour(colour)
    {
    }

    Sprite(float x, float y, float z, int texNumber):x(x), y(y), z(z), texNumber(texNumber), colour(0x00000000)
    {
    }

    float x;
    float y;
    float z;
    int texNumber;
    unsigned int colour;
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

    Vector3 operator + (Vector3 rhs)
    {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
};

#endif
