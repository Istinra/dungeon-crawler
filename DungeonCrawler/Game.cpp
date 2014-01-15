//
//  Game.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <SDL_scancode.h>
#include "Game.h"

Game::Game()
{

}

void Game::NewGame()
{
    level.LoadLevel("demo");
    level.AddEntity(&player);
}

void Game::LoadLevel(std::string name)
{
    level.RemoveEntity(&player);
    level = Level();
    level.LoadLevel(name);
    level.AddEntity(&player);
}

void Game::Update(bool const *keys)
{
    if (player.Alive())
    {
        HandleInput(keys);
        level.Update();
    }
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

    Vector3 movement(0, 0, 0);
    if (keys[SDL_SCANCODE_W])
    {
        movement.z -= sinf(yaw) * MOVE_STEP;
        movement.x += cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_S])
    {
        movement.z += sinf(yaw) * MOVE_STEP;
        movement.x -= cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_Q])
    {
        movement.x -= sinf(yaw) * MOVE_STEP;
        movement.z -= cosf(yaw) * MOVE_STEP;
    }
    if (keys[SDL_SCANCODE_E])
    {
        movement.x += sinf(yaw) * MOVE_STEP;
        movement.z += cosf(yaw) * MOVE_STEP;
    }

    if (movement.x != 0 || movement.y != 0 || movement.z != 0)
    {
        player.Move(movement);
    }

    if (keys[SDL_SCANCODE_F])
    {
        player.Action();
    }
    player.Yaw(yaw);
}

Game::~Game()
{
    level.RemoveEntity(&player);
}
