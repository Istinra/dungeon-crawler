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
	Uint32 amount = s->dataLength - s->dataPos;
	if (amount > len) {
		amount = len;
	}
	memset(stream, 0, len);
	SDL_MixAudio(stream, &s->data[s->dataPos], amount, SDL_MIX_MAXVOLUME);
	s->dataPos += amount;
}

SoundManager::SoundManager() : activeSound(nullptr)
{

}

SoundManager::~SoundManager()
{
	SDL_CloseAudio();
    for (auto val : soundMap)
    {
        SDL_FreeWAV(val.second->data);
        delete val.second;
    }
}

void SoundManager::PlaySound(Sounds sound)
{
	Sound *soundObject = nullptr;
	switch (sound)
	{
	case SOUND:
		soundObject = InitSound(sound, "..\\DungeonCrawler\\Art\\hit.wav");
		break;
	case LASER:
		soundObject = InitSound(sound, "..\\DungeonCrawler\\Art\\laser.wav");
	default:
		return;
	}
	if (soundObject)
	{
		soundObject->dataPos = 0;
		SDL_OpenAudio(&soundObject->wave, NULL);
		SDL_PauseAudio(0);
	}
    activeSound = soundObject;
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
		SDL_LoadWAV(file, &s->wave, &s->data, &s->dataLength);
		s->wave.callback = AudioCallback;
		s->wave.userdata = s;
		s->dataPos = 0;
        soundMap[sounds] = s;
        return s;
    }
    return soundMap[sounds];
}

void SoundManager::Update()
{
	if (activeSound != nullptr && activeSound->dataPos >= activeSound->dataLength)
	{
//		
		activeSound = nullptr;
	}
}
