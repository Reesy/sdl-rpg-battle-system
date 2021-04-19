#include <iostream>
#include <Skeleton.hpp>
#include <Animator.hpp>

Skeleton::Skeleton(SDL_Texture *_texture,  SDL_Texture *_idleTexture)
{
    tthis->texture = _texture;
    this->idleTexture = _idleTexture;
    this->textureRect = {0, 0, 32, 32};
    this->positionRect = {0, 0, 6, 6};
    this->isIdle = false;
    this->attackAnimation = new Animator(5, 5, 32, 32);

};

void Skeleton::move(int _x, int _y)
{
    this->positionRect.x += _x;
    this->positionRect.y += _y;
};

void Skeleton::animate(double elapsedTime)
{

    if ( this->isIdle ) 
    {
        this->sprite = this->attackAnimation->Animate(elapsedTime, this->sprite);
    }
    else 
    {   
        this->sprite = this->attackAnimation->Animate(elapsedTime, this->sprite);
    }
};

void Skeleton::render(RenderWindow &window)
{   
    SDL_RenderCopy(_renderer, this->texture, &this->textureRect, &this->positionRect);
};

void Skeleton::setIdle(bool _idle)
{
    this->isIdle = _idle;
}

int Skeleton::getX()
{
    return x;
}

int Skeleton::getY()
{
    return y;
}
