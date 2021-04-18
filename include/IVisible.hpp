#include <SDL.h>
#include <SDL_image.h>
#pragma once
class IVisible
{
    private: 
        SDL_Texture *texture;
        SDL_Texture *sprite;
    public: 
        virtual void render(SDL_Renderer *_renderer) = 0;
};