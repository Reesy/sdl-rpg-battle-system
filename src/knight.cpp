#include <iostream>
#include <Knight.hpp>
#include <Animator.hpp>

Knight::Knight(SDL_Texture *_texture, SDL_Texture *_idleTexture)
{
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->sprite.setTexture(this->idleTexture);
    this->sprite.setTextureRect( IntRect(0, 0, 200, 200));
    this->x = 0;
    this->y = 0;
    this->isIdle = true;
    this->sprite.setScale(10, 10);
    this->attackAnimation = new Animator(26, 14, 120, 60);
    this->idleAnimation = new Animator(5, 7, 120, 60);

};

void Knight::move(int _x, int _y)
{
    x += _x;
    y += _y;
    this->sprite.move(_x, _y);
};

void Knight::animate(double elapsedTime)
{
    if ( this->isIdle ) 
    {
        this->sprite.setTexture(this->idleTexture);
        this->sprite = this->idleAnimation->Animate(elapsedTime, this->sprite);
    }
    else 
    {   
        this->sprite.setTexture(this->texture);
        this->sprite = this->attackAnimation->Animate(elapsedTime, this->sprite);
    
    }
};

void Knight::render(SDL_Renderer *_renderer)
{   
    window.draw(this->sprite);
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
