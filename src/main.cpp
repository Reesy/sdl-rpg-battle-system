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
sf::RenderWindow window(sf::VideoMode(1920, 1080), "SDL RPG BATTLE SYSTEM");
sf::Event event;
sf::Font font;
sf::Text attack_text("Attack", font);
sf::Text escape_text("Escape", font);
sf::Time game_time;
sf::Music menu_change_sound;
sf::Texture menu_texture;
sf::Sprite cursor_sprite;
sf::Image icon;

//Characters 

sf::Texture knight_texture_sheet;
sf::Texture slime_texture_sheet;
sf::Texture knight_idle_sheet;
sf::Texture skeleton_texture_sheet;

Knight* knight;
Slime* slime;
Slime* slime2;
Skeleton* skeleton;
Menu* menu;
bool selecting_attack = true;

const sf::Color background_color(91, 10, 145);

static void update(float elapsed)
{
    if (selecting_attack)
    {
        cursor_sprite.setPosition(300, 910);
    }   
    else
    {
        cursor_sprite.setPosition(1000, 910);
    }
    
};

static void render()
{
    menu->render(window);
    knight->render(window);
    slime->render(window);
    slime2->render(window);
    skeleton->render(window);
    window.draw(attack_text);
    window.draw(escape_text);
    window.draw(cursor_sprite);
};

static void input()
{
    
    if (event.type == sf::Event::Closed) 
    {
        
        window.close();
    }
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
    {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
    {
        if (selecting_attack)
        {
            selecting_attack = false;
            menu_change_sound.play();
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
    {
        if (!selecting_attack)
        {
            selecting_attack = true;
            menu_change_sound.play();
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    {
        if (selecting_attack)
        {
            knight->setIdle(false);
        }
    }

}

static void loadResources()
{
    font.loadFromFile("resources/sansation.ttf");
    menu_texture.loadFromFile("resources/ff_menu.png");
    menu_change_sound.openFromFile("resources/ff_bleep.ogg");
	icon.loadFromFile("resources/icon.png");
    knight_texture_sheet.loadFromFile("resources/knight_spritesheet.png");
    knight_idle_sheet.loadFromFile("resources/knight_idle.png");
    slime_texture_sheet.loadFromFile("resources/slime_spritesheet.png");
    skeleton_texture_sheet.loadFromFile("resources/skeleton.png");
};

static void init()
{
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
    menu = new Menu(menu_texture);
    menu->move(0, 830);

    attack_text.setCharacterSize(60);
    attack_text.setStyle(sf::Text::Bold);
    attack_text.setFillColor(sf::Color::White);
    attack_text.move(400, 920);
    escape_text.setCharacterSize(60);
    escape_text.setStyle(sf::Text::Bold);
    escape_text.setFillColor(sf::Color::White);
    escape_text.move(1100, 920);

    cursor_sprite.setTexture(menu_texture);
    cursor_sprite.setTextureRect(sf::IntRect(241, 223.3, 17, 17));
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
    sf::Clock clock;
    game_time = clock.restart();

    while (window.isOpen())
    {
        
        sf::Time elapsed = clock.restart();
        
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