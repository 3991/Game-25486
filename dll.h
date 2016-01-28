#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>

class dll {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice;
        sf::Font font;
        sf::Texture textureFolder, textureClose;
        sf::Sprite spriteFodler, spriteClose;

    public:
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);
        int load() ;
};



#endif // DLL_H
