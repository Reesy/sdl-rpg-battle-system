#include <SDL.h>
#include <SDL_image.h>
#include <IVisible.hpp>

#pragma once
class IAnimatable: public IVisible
{   
    public: 
        virtual void animate(double _elapsedTime) = 0;
        virtual void render(SDL_Renderer *_renderer) = 0;
};
