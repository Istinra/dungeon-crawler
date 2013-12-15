//
//  Entity.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Entity_h
#define DungeonCrawler_Entity_h

#include "Common/Vector.h"

class Entity
{

public:
    Entity();
    virtual ~Entity();

    Vector3 const Position()
    {
        return position;
    }

    void Position(Vector3 pos)
    {
        position = pos;
    }

    float Yaw()
    {
        return yaw;
    }

    void Yaw(float yaw)
    {
        this->yaw = yaw;
    }

    Sprite *ActiveSprite()
    {
        return sprite;
    }

protected:
    Sprite *sprite;
    Vector3 position;
    float yaw;
};

#endif
