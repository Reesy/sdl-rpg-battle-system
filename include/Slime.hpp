#include <IMovable.hpp>
#include <IAnimatable.hpp>
#include <Animator.hpp>
#pragma once

class Slime: public IMovable,
            public IAnimatable
{
    private:
        int x,y;
        SDL_Texture *texture;
        SDL_Texture *idleTexture;
        SDL_Rect textureRect;
        SDL_Rect positionRect;
        float animationFrameTimer;
        float isIdle;
        Animator* attackAnimation;
        SDL_RendererFlip flip;

        
    public: 
        Slime(SDL_Texture *_texture, SDL_Texture *_idleTexture);
        void move(int _x, int _y);
        void render(SDL_Renderer *_renderer);
        void animate(double _elapsedTime);
        void setIdle(bool _idle);
        int getX();
        int getY(); 
};
