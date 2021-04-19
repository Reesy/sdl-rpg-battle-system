#include <IMovable.hpp>
#include <IVisible.hpp>
#pragma once

class Menu: public IMovable,
            public IVisible
{
    private:
        int x,y;
        SDL_Texture* texture;
        SDL_Rect textureRect;
        SDL_Rect positionRect;
      
    public: 
        Menu(SDL_Texture* _texture);
        void move(int _x, int _y);
        void render(SDL_Renderer *_renderer);
        int getX();
        int getY(); 
};
