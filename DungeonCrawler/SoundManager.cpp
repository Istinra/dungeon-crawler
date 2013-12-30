//
//  SoundManager.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 30/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "SoundManager.h"

void AudioCallback(void *userdata, Uint8 *stream, int len)
{

}

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
    for (auto val : soundMap)
    {
SDL_FreeWAV(val.second->wavBuffer);
delete val.second;
}
    SDL_CloseAudio();
}

void SoundManager::PlaySound(Sounds sound)
{
Sound *soundObject;
switch (sound)
{
case SOUND:
soundObject = InitSound(sound, "/Users/sam/Documents/DungeonCrawler/DungeonCrawler/Art/hit.wav");
SDL_OpenAudio(&soundObject->wavSpec, nullptr);
SDL_PauseAudio(0);
break;
default:
return;
}

}

SoundManager &SoundManager::Instance()
{
    static SoundManager sm;
    return sm;
}

Sound *SoundManager::InitSound(Sounds sounds, const char *file)
{
if (soundMap.find(sounds) == soundMap.end())
{
Sound *s = new Sound;
SDL_LoadWAV(file, &s->wavSpec, &s->wavBuffer, &s->wavLength);
s->wavSpec.callback = AudioCallback;
s->wavSpec.userdata = s;
soundMap[sounds] = s;
return s;
}
return soundMap[sounds];
}
