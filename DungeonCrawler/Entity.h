//
//  Entity.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Entity_h
#define DungeonCrawler_Entity_h

#define MOVE_STEP 0.5f
#define TURN_STEP 0.009f

#include "Common/CommonTypes.h"
#include "Item.h"

class Level;

class Entity
{

public:
    Entity(Vector3 position);

    virtual ~Entity();

    virtual void Move(Vector3 movement);

    bool ContainsPoint(float x, float z);

    virtual bool Use(Entity *source, Item &item);

    virtual void Update();

    virtual void Collide(Entity *e);

    virtual bool IsRemoved()
    {
        return false;
    }

    void SetLevel(Level *level);

    Vector3 const Position() const
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

protected:
    static const float boundingWidth;
    Level *level;
    Sprite *sprite;
    Vector3 position;
    float yaw;
};

#endif
