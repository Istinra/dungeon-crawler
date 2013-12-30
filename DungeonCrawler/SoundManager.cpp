//
//  SoundManager.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 30/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include "SoundManager.h"

static Uint8 *audio_pos;
static Uint32 audio_len;

void AudioCallback(void *userdata, Uint8 *stream, int len)
{
    Sound *s = reinterpret_cast<Sound *>(userdata);
    s->wavSpec.userdata = s;
    if (s->wavLength == 0)
    {
        return;
    }

    len = (len > s->wavLength ? s->wavLength : len);
    //SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
    SDL_MixAudio(stream, s->wavBuffer, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

    s->wavBuffer += len;
    s->wavLength -= len;
}

SoundManager::SoundManager() : activeSound(nullptr)
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

void SoundManager::Update()
{
    if (activeSound != nullptr && activeSound->wavLength == 0)
    {
        SDL_CloseAudio();
    }
}
