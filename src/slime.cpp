#include <iostream>
#include <Slime.hpp>
#include <Animator.hpp>

Slime::Slime(SDL_Texture *_texture,  SDL_Texture *_idleTexture)
{
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->textureRect = {0, 0, 70, 70};
    this->positionRect = {0, 0, 150, 150};
    this->isIdle = false;
     this->attackAnimation = new Animator(48, 14, 70, 70);

};

void Slime::move(int _x, int _y)
{
    this->positionRect.x += _x;
    this->positionRect.y += _y;
};

void Slime::animate(double elapsedTime)
{

    if ( this->isIdle ) 
    {
        this->texture = this->attackAnimation->Animate(elapsedTime, this->texture);
    }
    else 
    {   
        this->texture = this->attackAnimation->Animate(elapsedTime, this->texture);
    }
};

void Slime::render(SDL_Renderer *_renderer)
{   
    SDL_RenderCopy(_renderer, this->texture, &this->textureRect, &this->positionRect);
};

void Slime::setIdle(bool _idle)
{
    this->isIdle = _idle;
}

int Slime::getX()
{
    return x;
}

int Slime::getY()
{
    return y;
}
