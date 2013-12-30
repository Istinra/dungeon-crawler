//
//  SoundManager.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 30/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__SoundManager__
#define __DungeonCrawler__SoundManager__

#include "Sound.h"
#include <map>

class SoundManager
{
public:
    ~SoundManager();

    void PlaySound(Sounds sound);

    static SoundManager &Instance();

private:
    SoundManager();

    Sound *InitSound(Sounds, const char *file);

    std::map<Sounds, Sound *> soundMap;
};

#endif /* defined(__DungeonCrawler__SoundManager__) */
