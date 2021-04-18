#include <SDL.h>
#include <SDL_image.h>

#pragma once
class Animator
{   
    private:
        int frameCount;
        float animationFrameTimer;
        float speed;
        float width;
        float height;
    public: 
        Animator(int _frameCount,
                   float _speed,
                   float _width,
                   float _height);
        SDL_Texture* Animate(float elapsedTime, SDL_Texture* Sprite);
};
