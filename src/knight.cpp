#include <iostream>
#include <Knight.hpp>
#include <Animator.hpp>

Knight::Knight(SDL_Texture *_texture, SDL_Texture *_idleTexture)
{
    this->isIdle = true;
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->textureRect = {0, 0, 120, 60};
    this->positionRect = {0, 0, 200, 200};
    this->attackAnimation = new Animator(26, 100, 120, 60);
    this->idleAnimation = new Animator(5, 200, 120, 60);
};

void Knight::move(int _x, int _y)
{
    this->positionRect.x += _x;
    this->positionRect.y += _y;
    return;
};

void Knight::animate(double elapsedTime)
{
    if ( this->isIdle ) 
    {
        this->idleAnimation->Animate(elapsedTime, &this->textureRect);
    }
    else 
    {   
        this->attackAnimation->Animate(elapsedTime, &this->textureRect);
    };
    return;
};

void Knight::render(SDL_Renderer *_renderer)
{   
    
    if ( this->isIdle ) 
    {
        SDL_RenderCopy(_renderer, this->idleTexture, &this->textureRect, &this->positionRect);
    }
    else 
    {   
        SDL_RenderCopy(_renderer, this->texture, &this->textureRect, &this->positionRect);
    };
    return;
};

void Knight::setIdle(bool _idle)
{
    this->isIdle = _idle;
    return;
}

int Knight::getX()
{
    return x;
}

int Knight::getY()
{
    return y;
}
