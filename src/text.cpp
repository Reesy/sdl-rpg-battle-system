#include <IText.hpp>
#include <iostream>


Text::Text(TTF_Font* _font, std::string _message, SDL_Color _color, SDL_Rect _position, SDL_Renderer* _renderer)
{
    this->font = _font;
    this->renderer = _renderer;
    this->position = _position;
    this->color = _color;
    SDL_Surface *textureSurface = TTF_RenderText_Blended(_font, _message.c_str(), _color);
    if (textureSurface == nullptr)
    {
        std::cout << "Issue creating surface texture when instantiating text: " << TTF_GetError() << std::endl;
        TTF_CloseFont(_font); 
    };

    this->texture = SDL_CreateTextureFromSurface(_renderer, textureSurface);    
}

Text::~Text()
{

};

void Text::updateText(std::string _newMessage) 
{
    SDL_Surface *textureSurface = TTF_RenderText_Blended(this->font, _newMessage.c_str(), this->color);
    if (textureSurface == nullptr)
    {
        std::cout << "Issue creating surface texture when instantiating text: " << TTF_GetError() << std::endl;
        TTF_CloseFont(this->font); 
    };

    this->texture = SDL_CreateTextureFromSurface(this->renderer, textureSurface); 
};

void Text::render(SDL_Renderer *_renderer)
{
    SDL_RenderCopy(_renderer, this->texture , NULL, &this->position);
};


void Text::move(int x, int y)
{

};