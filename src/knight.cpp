#include <iostream>
#include <Knight.hpp>
#include <Animator.hpp>

Knight::Knight(SDL_Texture *_texture, SDL_Texture *_idleTexture)
{
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->textureRect = {0, 0, 120, 60};
    this->positionRect = {0, 0, 200, 200};
 //   this->sprite.setTexture(this->idleTexture);
 //   this->sprite.setTextureRect( IntRect(0, 0, 200, 200));
  //  this->sprite.setScale(10, 10);
    this->attackAnimation = new Animator(26, 14, 120, 60);
    this->idleAnimation = new Animator(5, 7, 120, 60);

};

void Knight::move(int _x, int _y)
{
    this->positionRect.x += _x;
    this->positionRect.y += _y;
};

void Knight::animate(double elapsedTime)
{
    if ( this->isIdle ) 
    {
        this->texture = this->idleTexture;
        this->texture = this->idleAnimation->Animate(elapsedTime, this->texture);
    }
    else 
    {   
        this->texture = this->texture;
        this->texture = this->attackAnimation->Animate(elapsedTime, this->texture);
    
    }
};

void Knight::render(SDL_Renderer *_renderer)
{   
    SDL_RenderCopy(_renderer, this->texture, &this->textureRect, &this->positionRect);
};

void Knight::setIdle(bool _idle)
{
    this->isIdle = _idle;
}

int Knight::getX()
{
    return x;
}

int Knight::getY()
{
    return y;
}
