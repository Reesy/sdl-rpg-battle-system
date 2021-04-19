#include <Animator.hpp>


Animator::Animator(int _frameCount,
                   float _speed,
                   float _width,
                   float _height)
{
    frameCount = _frameCount - 1; //indexing starts at zero
    speed = _speed;
    width = _width;
    height = _height;
};

SDL_Texture* Animator::Animate(double _elapsedTime, SDL_Texture *_sprite)
{
    animationFrameTimer += _elapsedTime * speed;
    
    int frame = floor(animationFrameTimer);

    int framePosition = frame * width;
    
    if (frame >= frameCount)
    {
        animationFrameTimer = 0;
        frame = 0;
    } 
        
    return _sprite;
};