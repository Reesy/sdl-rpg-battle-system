#include <SDL.h>
#include <SDL_image.h>
#pragma once
class IVisible
{
    public: 
        virtual void render(SDL_Renderer *_renderer) = 0;
};