#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <IMovable.hpp>
#include <IVisible.hpp>

class Text: public IMovable,
            public IVisible
{
    private:
        SDL_Rect position;
        SDL_Texture *texture;
        TTF_Font *font;
        std::string message;
        SDL_Color color;
        SDL_Renderer* renderer;

    public:
        Text(TTF_Font* _font, std::string _message, SDL_Color _color, SDL_Rect _position, SDL_Renderer* _renderer);
        ~Text();
        void render(SDL_Renderer *_renderer);
        void move(int x, int y);
        void updateText(std::string _newMessage);

};