#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <IVisible.hpp>
#include <IAnimatable.hpp>
#include <IMovable.hpp>
#include <Menu.hpp>
#include <Knight.hpp>
#include <Slime.hpp>
#include <Skeleton.hpp>

#if __EMSCRIPTEN__
	#include <emscripten/emscripten.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_mixer.h>
#else
	#include <SDL.h>
	#include <SDL_image.h>
    #include <SDL_ttf.h>
    #include <SDL_mixer.h>
#endif


//game objects
SDL_Event *event = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;
// Text attack_text("Attack", font);
// Text escape_text("Escape", font);
Mix_Chunk *menu_change_sound = NULL;
SDL_Texture *menu_texture = NULL;
SDL_Texture *cursor_sprite = NULL;
SDL_Surface *icon = NULL;

//Characters 

SDL_Texture *knight_texture_sheet = NULL;
SDL_Texture *slime_texture_sheet = NULL;
SDL_Texture *knight_idle_sheet = NULL;
SDL_Texture *skeleton_texture_sheet = NULL;

Knight* knight;
Slime* slime;
Slime* slime2;
Skeleton* skeleton;
Menu* menu;
bool selecting_attack = true;
bool quit = false;

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr)
	{
        printf("Failed to load image\n", file.c_str());
        std::cout << "Failure reason: " << IMG_GetError() << std::endl;
	}
	return texture;
}


static void update(float elapsed)
{
    return;
    // if (selecting_attack)
    // {
    //     cursor_sprite.setPosition(300, 910);
    // }   
    // else
    // {
    //     cursor_sprite.setPosition(1000, 910);
    // }
    
};

static void render()
{

    SDL_SetRenderDrawColor(renderer, 91, 10, 145, 255);
    SDL_RenderClear(renderer);
    


    menu->render(renderer);
    knight->render(renderer);
    slime->render(renderer);
    slime2->render(renderer);
    skeleton->render(renderer);


    // window.draw(attack_text);
    // window.draw(escape_text);
    // window.draw(cursor_sprite);


    SDL_RenderPresent(renderer);
};

static void input()
{
    
    if (event->type == SDL_QUIT) 
    {
        quit = true;
    };
    
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_RIGHT:
                if (selecting_attack)
                {
                    selecting_attack = false;
                    //menu_change_sound.play();
                };
                break;
            case SDLK_LEFT:
                if (!selecting_attack)
                {
                    selecting_attack = true;
                    //menu_change_sound.play();
                };
            case SDLK_RETURN:
                if (selecting_attack)
                {
                    knight->setIdle(false);
                };
            default:
                break;

        };
    };
};

static void loadResources()
{
  //  font.loadFromFile("resources/sansation.ttf");
    menu_texture = loadTexture("resources/ff_menu.png", renderer);
    knight_texture_sheet = loadTexture("resources/knight_spritesheet.png", renderer);
    knight_idle_sheet = loadTexture("resources/knight_idle.png", renderer);
    slime_texture_sheet = loadTexture("resources/slime_spritesheet.png", renderer);
    skeleton_texture_sheet = loadTexture("resources/skeleton.png", renderer);
   
    menu_change_sound = Mix_LoadWAV("resources/ff_bleep.ogg"); 
    if (menu_change_sound == NULL)
    {
        std::cout << "Faled to load menu change sound! SDL_MiXER_ERROR: " << Mix_GetError() << std::endl;
    }

    icon = IMG_Load("resources/icon.png");
    if (icon == NULL)
    {
        std::cout << "Faled to load icon! SDL_Image error: " << IMG_GetError() << std::endl;
    }


};

static void init()
{
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
    menu = new Menu(menu_texture);
    menu->move(0, 830);

    attack_text.setCharacterSize(60);
    attack_text.setStyle( Text::Bold);
    attack_text.setFillColor( Color::White);
    attack_text.move(400, 920);
    escape_text.setCharacterSize(60);
    escape_text.setStyle( Text::Bold);
    escape_text.setFillColor( Color::White);
    escape_text.move(1100, 920);

    cursor_sprite.setTexture(menu_texture);
    cursor_sprite.setTextureRect( IntRect(241, 223.3, 17, 17));
    cursor_sprite.setScale(6, 6);
    cursor_sprite.setPosition(300, 910);


    knight = new Knight(knight_texture_sheet, knight_idle_sheet);
    slime = new Slime(slime_texture_sheet, slime_texture_sheet);
    slime2 = new Slime(slime_texture_sheet, slime_texture_sheet);
    skeleton = new Skeleton(skeleton_texture_sheet, skeleton_texture_sheet);
    slime->move(1000, 0);
    slime2->move(1200, 200);
    skeleton->move(1500, 550);
};

int main(int, char const**)
{

    loadResources();
    init();
    Clock clock;
    game_time = clock.restart();

    while (window.isOpen())
    {
        
         Time elapsed = clock.restart();
        
        while (window.pollEvent(event))
        {
            input();
        }
        
        window.clear(background_color);
        knight->animate(elapsed.asSeconds());
        slime->animate(elapsed.asSeconds());
        slime2->animate(elapsed.asSeconds());
        skeleton->animate(elapsed.asSeconds());
        update(elapsed.asSeconds());
        render();
        
        window.display();
        
    };
    menu_change_sound.~Music();
    return EXIT_SUCCESS;
};