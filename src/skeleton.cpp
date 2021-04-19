#include <iostream>
#include <Skeleton.hpp>
#include <Animator.hpp>

Skeleton::Skeleton( Texture _texture,  Texture _idleTexture)
{
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect( IntRect(0, 0, 32, 32));
    this->x = 0;
    this->y = 0;
    this->isIdle = false;
    this->sprite.setScale(6, 6);
    this->attackAnimation = new Animator(5, 5, 32, 32);

};

void Skeleton::move(int _x, int _y)
{
    x += _x;
    y += _y;
    this->sprite.move(_x, _y);
};

void Skeleton::animate(float elapsedTime)
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
    window.draw(this->sprite);
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
