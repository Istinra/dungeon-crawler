//
//  main.cpp
//  DungeonCrawler
//
//  Created by Samuel Hands on 6/12/2013.
//  Copyright (c) 2013 Sam. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window* window = SDL_CreateWindow("Dungeon Crawler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        std::cout << "Could not init Window " << SDL_GetError();
        return 1;
    }
    
    SDL_Delay(3000);
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}

