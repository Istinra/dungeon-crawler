//
//  Game.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 8/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <SDL2/SDL_scancode.h>
#include "Game.h"

Game::Game()
{

}

void Game::Update(bool const *keys) {
    HandleInput(keys);
}

void Game::HandleInput(bool const *keys) {
    Vector3 position = player.Position();
    if (keys[SDL_SCANCODE_W]) {
        position.z -= 0.1f;
    }
    if (keys[SDL_SCANCODE_S]) {
        position.z += 0.1f;
    }
    if (keys[SDL_SCANCODE_A]) {
        position.x += 0.1f;
    }
    if (keys[SDL_SCANCODE_D]) {
        position.x -= 0.1f;
    }
    player.Position(position);
}
