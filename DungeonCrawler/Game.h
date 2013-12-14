//
//  Game.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Game_h
#define DungeonCrawler_Game_h

#include "Player.h"
#include "Map/Level.h"

class Game
{
public:
    Game();

    Player &GetPlayer()
    {
        return player;
    }

    void NewGame();

    void Update(bool const *keys);

    Level &CurrentLevel()
    {
        return level;
    }

private:
    void HandleInput(bool const *keys);

    Player player;
    Level level;
};

#endif
