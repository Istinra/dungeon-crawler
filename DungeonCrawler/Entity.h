//
//  Entity.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Entity_h
#define DungeonCrawler_Entity_h

#include "CommonTypes.h"

class Level;

class Entity
{

public:
    Entity();
    virtual ~Entity();

    void Move(Vector3 movement);

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

    void SetSprite(Sprite *sprite)
    {
        this->sprite = sprite;
    }

    void SetLevel(Level *level);

protected:
    static const float boundingWidth;
    Level *level;
    Sprite *sprite;
    Vector3 position;
    float yaw;
};

#endif
