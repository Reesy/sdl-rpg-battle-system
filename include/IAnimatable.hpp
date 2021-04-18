#include <SDL.h>
#include <SDL_image.h>
#include <IVisible.hpp>

#pragma once
class IAnimatable: public IVisible
{   
    private:
        SDL_Texture* texture;
        SDL_Texture* sprite;
    public: 
        virtual void animate(double _elapsedTime) = 0;
        virtual void render(SDL_Renderer *_renderer) = 0;
};
