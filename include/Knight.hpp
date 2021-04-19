#include <IMovable.hpp>
#include <IAnimatable.hpp>
#include <Animator.hpp>
#pragma once

class Knight: public IMovable,
            public IAnimatable
{
    private:
        int x,y;
        SDL_Texture *texture;
        SDL_Texture *idleTexture;
        SDL_Texture *sprite;
        float animationFrameTimer;
        float isIdle;
        Animator* attackAnimation;
        Animator* idleAnimation;
        
    public: 
        Knight(SDL_Texture* _texture, SDL_Texture* _idleTexture);
        void move(int _x, int _y);
        void render(SDL_Renderer *_renderer);
        void animate(double _elapsedTime);
        void setIdle(bool _idle);
        int getX();
        int getY(); 
};
