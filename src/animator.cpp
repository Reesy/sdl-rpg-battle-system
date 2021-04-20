#include <Animator.hpp>
#include <iostream>

Animator::Animator(int _numberOfFrames,
                   int _frameDuration,
                   float _width,
                   float _height)
{
    numberOfFrames = _numberOfFrames; //indexing starts at zero
    frameDuration = _frameDuration;
    width = _width;
    height = _height;
    currentFrameNumber = 0;
};

void Animator::Animate(double _dt, SDL_Rect* _textureRect)
{
    animationFrameTimer += _dt;

    if (animationFrameTimer >= frameDuration)
    {  
        animationFrameTimer = 0;
        if (currentFrameNumber >= (numberOfFrames - 1))
        {

            currentFrameNumber = 0;
            _textureRect->x = 0;
            return;
        };

        currentFrameNumber++;
        _textureRect->x = currentFrameNumber * width;
    };

    return;
};