#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>

class dll {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice;
        sf::Font font;
    public:
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);
        int load() ;
};



#endif // DLL_H
