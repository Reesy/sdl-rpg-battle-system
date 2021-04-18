#include <IMovable.hpp>
#include <IAnimatable.hpp>
#include <Animator.hpp>
#pragma once

class Slime: public IMovable,
            public IAnimatable
{
    private:
        int x,y;
        sf::Texture texture;
        sf::Texture idleTexture;
        sf::Sprite sprite;
        float animationFrameTimer;
        float isIdle;
        Animator* attackAnimation;

        
    public: 
        Slime(sf::Texture _texture, sf::Texture _idleTexture);
        void move(int x, int y);
        void render(sf::RenderWindow &window);
        void animate(float elapsedTime);
        void setIdle(bool _idle);
        int getX();
        int getY(); 
};
