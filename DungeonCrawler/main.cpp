//
//  main.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 6/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <random>

#define WIDTH 640
#define HEIGHT 480

void Render(SDL_Window* const window)
{
    SDL_Surface* screen = SDL_GetWindowSurface(window);

    if (SDL_MUSTLOCK(screen) && SDL_LockSurface(screen) < 0)
    {
        return;
    }
    for (unsigned i = 0; i < WIDTH * HEIGHT; i++)
    {
        ((unsigned *)screen->pixels)[i] = (unsigned int) i * 10;
    }
    if (SDL_MUSTLOCK(screen))
    {
        SDL_UnlockSurface(screen);
    }
    SDL_UpdateWindowSurface(window);
}

int main(int argc, const char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    
    SDL_Window* window = SDL_CreateWindow("Dungeon Crawler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

    if (window == nullptr)
    {
        std::cout << "Could not init Window " << SDL_GetError();
        return 1;
    }
    bool running = true;
    bool keys[323] = { false };

    unsigned frames = 0;
    float frequency = (float) SDL_GetPerformanceFrequency();
    float totalTime = 0;
    float dt = 0;
    
    Uint64 oldTime = SDL_GetPerformanceCounter();
    Uint64 newTime = oldTime;
    
    while (running)
    {
        ++frames;
        newTime = SDL_GetPerformanceCounter();
        dt = (newTime - oldTime) / frequency;
        totalTime += dt;
        oldTime = newTime;
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    keys[event.key.keysym.sym] = true;
                    break;
                case SDL_KEYUP:
                    keys[event.key.keysym.sym] = false;
                    break;
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
        Render(window);
        if (frames % 100 == 0)
        {
            std::cout << "FPS: " << frames / totalTime << std::endl;
        }
        SDL_Delay(1);
    }
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}

