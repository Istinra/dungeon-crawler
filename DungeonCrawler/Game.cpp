//
//  Game.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <SDL2/SDL_scancode.h>
#include "Game.h"

#define MOVE_STEP 0.25f
#define TURN_STEP 0.005f

Game::Game()
{

}

void Game::NewGame()
{
    level.LoadLevel("demo");
}

void Game::Update(bool const *keys)
{
    HandleInput(keys);
}

void Game::HandleInput(bool const *keys)
{
    float yaw = player.Yaw();
    if (keys[SDL_SCANCODE_A])
    {
        yaw += TURN_STEP;

    }
    if (keys[SDL_SCANCODE_D])
    {
        yaw -= TURN_STEP;
    }
    if (yaw > M_PI * 2) yaw = 0;
    if (yaw < 0) yaw = static_cast<float>(M_PI * 2);

    Vector3 position = player.Position();
    if (keys[SDL_SCANCODE_W])
    {
        position.z -= sinf(yaw) * MOVE_STEP;
        position.x += cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_S])
    {
        position.z += sinf(yaw) * MOVE_STEP;
        position.x -= cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_Q])
    {
        position.x -= sinf(yaw) * MOVE_STEP;
        position.z -= cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_E])
    {
        position.x += sinf(yaw) * MOVE_STEP;
        position.z += cosf(yaw) * MOVE_STEP;
    }

    player.Position(position);
    player.Yaw(yaw);
}
