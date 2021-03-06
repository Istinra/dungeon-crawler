//
//  main.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 14/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <iostream>
#include <SDL.h>
#include <random>
#include "Resources.h"
#include "Renderer.h"
#include "SoundManager.h"

void Render(SDL_Window *const window, Renderer &renderer)
{
    SDL_Surface *screen = SDL_GetWindowSurface(window);

    if (SDL_MUSTLOCK(screen) && SDL_LockSurface(screen) < 0)
    {
        return;
    }
	memcpy(screen->pixels, renderer.Pixels(), WIDTH * HEIGHT * sizeof(unsigned int));

    if (SDL_MUSTLOCK(screen))
    {
        SDL_UnlockSurface(screen);
    }
    SDL_UpdateWindowSurface(window);
}

int main(int argc, char *argv[])
{
    //SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window *window = SDL_CreateWindow("Dungeon Crawler", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    if (window == nullptr)
    {
        std::cout << "Could not init Window " << SDL_GetError();
        return 1;
    }
    bool running = true;

	//unsigned int frames = 0;
 //   float frequency = (float) SDL_GetPerformanceFrequency();
 //   float totalTime = 0;
 //   float dt = 0;

    Uint64 oldTime = SDL_GetPerformanceCounter();
    Uint64 newTime;
	
    Renderer renderer;
	Game game;
    game.NewGame();

    while (running)
    {
        //++frames;
        //newTime = SDL_GetPerformanceCounter();
        //dt = (newTime - oldTime) / frequency;
        //totalTime += dt;
        //oldTime = newTime;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
        bool const *keys = reinterpret_cast<bool const *>(SDL_GetKeyboardState(nullptr));
        game.Update(keys);
        renderer.Draw(game);
        Render(window, renderer);
        SoundManager::Instance().Update();
#ifdef DEBUG
        if (frames % 100 == 0)
        {
            std::cout << "FPS: " << frames / totalTime << '\n';
        }
#endif
        SDL_Delay(2);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

