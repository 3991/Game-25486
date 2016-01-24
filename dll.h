#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>

class dll {
    private:
        sf::RectangleShape rectTitle;
    public:
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);
};



#endif // DLL_H
