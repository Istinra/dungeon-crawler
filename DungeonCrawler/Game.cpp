//
//  Game.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <SDL_scancode.h>
#include "Game.h"
#include "NotificationManager.h"

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
	NotificationManager::Instance().Tick();
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

	if (keys[SDL_SCANCODE_1])
	{
		player.ActiveItem(0);
	}
	if (keys[SDL_SCANCODE_2])
	{
		player.ActiveItem(1);
	}
	if (keys[SDL_SCANCODE_3])
	{
		player.ActiveItem(2);
	}
	if (keys[SDL_SCANCODE_4])
	{
		player.ActiveItem(3);
	}
	if (keys[SDL_SCANCODE_5])
	{
		player.ActiveItem(4);
	}
	if (keys[SDL_SCANCODE_6])
	{
		player.ActiveItem(5);
	}
}

Game::~Game()
{
    level.RemoveEntity(&player);
}
