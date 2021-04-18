#include <IMovable.hpp>
#include <IVisible.hpp>
#pragma once

class Menu: public IMovable,
            public IVisible
{
    private:
        int x,y;
        sf::Texture texture;
        sf::Sprite sprite;
        
    public: 
        Menu(sf::Texture _texture);
        void move(int x, int y);
        void render(sf::RenderWindow &window);
        int getX();
        int getY(); 
};
