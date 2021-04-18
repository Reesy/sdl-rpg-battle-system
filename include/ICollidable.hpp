#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <IGameObject.hpp>
#pragma once
class ICollidable
{
    SDL_Rect bounds;
    public:
        virtual std::vector<GameObject> getBounds() = 0;
        virtual void renderCollider(SDL_Renderer *_renderer) = 0;
};