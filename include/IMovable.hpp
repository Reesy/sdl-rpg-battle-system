#include <SDL.h>
#include <SDL_image.h>

#pragma once

class IMovable
{
    public:
        virtual void move(int x, int y) = 0;
};