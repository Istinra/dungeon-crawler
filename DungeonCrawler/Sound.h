//
//  Sound.h
//  DungeonCrawler
//
//  Created by Samuel Hands on 30/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#ifndef __DungeonCrawler__Sound__
#define __DungeonCrawler__Sound__

#include <SDL.h>

enum Sounds
{
    SOUND,
	LASER,
	LADDER,
	HURT
};

struct Sound
{
	SDL_AudioSpec wave;
	unsigned char* data;
	unsigned int dataLength;
	unsigned int dataPos;
};

#endif /* defined(__DungeonCrawler__Sound__) */
