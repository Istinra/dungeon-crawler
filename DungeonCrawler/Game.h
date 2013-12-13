//
//  Game.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 7/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef DungeonCrawler_Game_h
#define DungeonCrawler_Game_h

#include "Player.h"

class Game
{
public:
    Game();

    Player &GetPlayer() {
        return player;
    }

    void Update(bool const *keys);

private:
    void HandleInput(bool const *keys);

    Player player;

};

#endif
