#include <iostream>
#include <Menu.hpp>

Menu::Menu( Texture _texture)
{
    this->texture = _texture;
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect( IntRect(98, 1, 143, 25));
    this->sprite.setScale(13.42, 10);
    this->x = 0;
    this->y = 0;
};

void Menu::move(int _x, int _y)
{
    x += _x;
    y += _y;
    this->sprite.move(_x, _y);
};

void Menu::render( RenderWindow &window)
{
    window.draw(this->sprite);
};


int Menu::getX()
{
    return x;
}

int Menu::getY()
{
    return y;
}