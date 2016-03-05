#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include <windows.h>
#include <tchar.h>
#include<SFML/Graphics/Font.hpp>
class dll {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice, rectTest;

sf::Text createThingText;
        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;

        // INTRO
        char str[80];

        // IN GAME
        sf::RectangleShape taskbar, buttonMainMenu, buttonsSubMenu;
        sf::Text anythingText;
        sf::Font font;
       // sf::Text creaThingText;
        sf::Font f;
    public:
        dll(void);
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);

        int load() ;

        void update(sf::RenderWindow &window);

        //INTRO
        void initIntro(sf::RenderWindow &window);
        void drawIntro(sf::RenderWindow &window);

        // IN GAME
        void initInterface(sf::RenderWindow &window);
        void drawInterface(sf::RenderWindow &window);
};



#endif // DLL_H
