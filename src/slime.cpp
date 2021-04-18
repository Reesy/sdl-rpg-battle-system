#include <iostream>
#include <Slime.hpp>
#include <Animator.hpp>

Slime::Slime(sf::Texture _texture, sf::Texture _idleTexture)
{
    this->texture = _texture;
    this->idleTexture = _idleTexture;
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    this->x = 0;
    this->y = 0;
    this->isIdle = false;
    this->sprite.setScale(6, 6);
    this->attackAnimation = new Animator(48, 14, 70, 70);

};

void Slime::move(int _x, int _y)
{
    x += _x;
    y += _y;
    this->sprite.move(_x, _y);
};

void Slime::animate(float elapsedTime)
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

void Slime::render(sf::RenderWindow &window)
{   
    window.draw(this->sprite);
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
