//
//  SoundManager.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 30/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
    for (auto val : soundMap)
    {
        SDL_FreeWAV(val.wavBuffer);
    }
    SDL_CloseAudio();
}

void SoundManager::PlaySound(Sounds sound)
{

}

SoundManager &SoundManager::Instance()
{
    static SoundManager sm;
    return sm;
}
