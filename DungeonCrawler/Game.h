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
#include <map>

class Game
{
public:
    Game();

    ~Game();

    Player &GetPlayer()
    {
        return player;
    }

    void NewGame();

    void Update(bool const *keys);

    Level &CurrentLevel()
    {
        return *currentLevel;
    }

private:
    void HandleInput(bool const *keys);
	void LoadLevel(std::string name);
	void RegisterLevel(std::string name, Level* level);

	std::map <std::string, Level*> levelMap;
	Level* currentLevel;

    Player player;
};

#endif
