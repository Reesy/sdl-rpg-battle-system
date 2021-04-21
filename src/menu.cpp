#include <iostream>
#include <Menu.hpp>

Menu::Menu(SDL_Texture *_texture)
{
    this->texture = _texture;
    this->textureRect = {98, 2, 143, 24};
    this->positionRect = {0, 0, 620, 90};
};

void Menu::move(int _x, int _y)
{
    this->positionRect.x += _x;
    this->positionRect.y += _y;
};

void Menu::render(SDL_Renderer *_renderer)
{
    SDL_RenderCopy(_renderer, this->texture, &this->textureRect, &this->positionRect);
};


int Menu::getX()
{
    return x;
};

int Menu::getY()
{
    return y;
};