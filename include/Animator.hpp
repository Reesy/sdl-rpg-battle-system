#include <SDL.h>
#include <SDL_image.h>

#pragma once
class Animator
{   
    private:
        int numberOfFrames;
        int currentFrameNumber;
        int frameDuration;
        double animationFrameTimer;
        float width;
        float height;
    public: 
        Animator(int _numberOfFrames,
                 int _frameDuration,
                 float _width,
                 float _height);
        void Animate(double _dt, SDL_Rect* _textureRect);
};
