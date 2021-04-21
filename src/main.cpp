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
#include <IText.hpp>

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

//Resources
SDL_Event *event = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font *font = NULL;
Text *attack_text = NULL;
Text *escape_text = NULL;
Mix_Chunk *menu_change_sound = NULL;
SDL_Surface *icon = NULL;
SDL_Texture *menu_texture = NULL;
SDL_Texture *cursor_texture = NULL;
SDL_Texture *knight_texture_sheet = NULL;
SDL_Texture *slime_texture_sheet = NULL;
SDL_Texture *knight_idle_sheet = NULL;
SDL_Texture *skeleton_texture_sheet = NULL;
SDL_Rect cursor_texture_rect;
SDL_Rect cursor_position_rect;
SDL_Color text_color;

//Entities
Knight* knight;
Slime* slime;
Slime* slime2;
Skeleton* skeleton;
Menu* menu;

//Global state
bool selecting_attack = true;
bool quit = false;

//Timing config
double dt = 10;
double currentTime = SDL_GetTicks();
double accumulator = 0.0;

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr)
	{
        std::cout << "Failed to load image: " << file.c_str() << "Failure reason: " << IMG_GetError() << std::endl;
	};
	return texture;
};

static void update()
{
    if (selecting_attack)
    {
        cursor_position_rect.x = 100;
    }   
    else
    {
        cursor_position_rect.x = 360;
    };
    return;
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

    SDL_RenderCopy(renderer, menu_texture, &cursor_texture_rect, &cursor_position_rect);

    attack_text->render(renderer);
    escape_text->render(renderer);

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
                selecting_attack =! selecting_attack;
                Mix_PlayChannel(-1, menu_change_sound, 0);
                break;
            case SDLK_LEFT:
                selecting_attack =! selecting_attack;
                Mix_PlayChannel(-1, menu_change_sound, 0);
                break;
            case SDLK_RETURN:
                if (selecting_attack)
                {
                    knight->setIdle(false);
                }
                else
                {
                    knight->setIdle(true);
                };
                break;
            default:
                break;
        };
    };
};

static void loadResources()
{
    menu_texture = loadTexture("resources/ff_menu.png", renderer);
    knight_texture_sheet = loadTexture("resources/knight_spritesheet.png", renderer);
    knight_idle_sheet = loadTexture("resources/knight_idle.png", renderer);
    slime_texture_sheet = loadTexture("resources/slime_spritesheet.png", renderer);
    skeleton_texture_sheet = loadTexture("resources/skeleton.png", renderer);
    
    icon = IMG_Load("resources/icon.png");
    if (icon == NULL)
    {
        std::cout << "Faled to load icon! SDL_Image error: " << IMG_GetError() << std::endl;
    };

    menu_change_sound = Mix_LoadWAV("resources/ff_bleep.ogg"); 
    if (menu_change_sound == NULL)
    {
        std::cout << "Faled to load menu change sound! SDL_MiXER_ERROR: " << Mix_GetError() << std::endl;
    };
    
    std::string fontPath = "resources/sansation.ttf";
    font = TTF_OpenFont(fontPath.c_str(), 40);
    if (font == NULL)
    {
        std::cout << "Failed to load font! SDL_font error" << TTF_GetError() << std::endl;
    };
};

static void init()
{
    SDL_SetWindowIcon(window, icon);

    menu = new Menu(menu_texture);
    menu->move(10, 270);
   
    text_color = {255, 255, 255, 255};
    
    SDL_Rect attack_text_position = {150, 290, 75, 50};
    attack_text = new Text(font, std::string("Attack"), text_color, attack_text_position, renderer);
    
    SDL_Rect escape_text_position = {410, 290, 75, 50};
    escape_text = new Text(font, std::string("Idle"), text_color, escape_text_position, renderer);

    cursor_texture_rect = {241, 223, 17, 17};
    cursor_position_rect = {100, 300, 50, 50};

    knight = new Knight(knight_texture_sheet, knight_idle_sheet);
    slime = new Slime(slime_texture_sheet, slime_texture_sheet);
    slime2 = new Slime(slime_texture_sheet, slime_texture_sheet);
    skeleton = new Skeleton(skeleton_texture_sheet, skeleton_texture_sheet);
    
    knight->move(50, 0);
    slime->move(500, -20);
    slime2->move(500, 105);
    skeleton->move(470, 100);

    Mix_Volume(-1, 20);
};

void gameLoop()
{
    double newTime = SDL_GetTicks();
    double frameTime = newTime - currentTime;

    if (frameTime > 250)
    {
        frameTime = 250;
    };

    currentTime = newTime;

    accumulator += frameTime;

    while (accumulator >= dt )
    {
        update();
        knight->animate(dt);
        slime->animate(dt);
        slime2->animate(dt);
        skeleton->animate(dt);
        accumulator -= dt;
    };

    render();

    while (SDL_PollEvent(event))
    {
        input();
    };
};

int main(int, char const**)
{

    //Start up SDL and make sure it went ok
	if ( SDL_Init (SDL_INIT_VIDEO) != 0 )
    {	
		throw "SDL could not be initialised";
	};
    
    int imgFlags = IMG_INIT_PNG;
    
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    };

 	//Also need to init SDL_ttf
	if (TTF_Init() != 0)
    {
		SDL_Quit();
		return 1;
	};

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    };
    
    window = SDL_CreateWindow("SDL RPG BATTLE SYSTEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!SDL_RenderSetLogicalSize(renderer, 640, 360))
    {
        std::cout << SDL_GetError() << std::endl;
    };

    event = new SDL_Event;
    
    loadResources();
    init();
    
    #if __EMSCRIPTEN__
		emscripten_set_main_loop(gameLoop, -1, 1);
	#else
		while (quit != true)
		{
			gameLoop();
		};
	#endif
    
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	renderer = NULL;
	window = NULL;
	IMG_Quit();
    TTF_Quit();
	SDL_Quit();

    return EXIT_SUCCESS;
};