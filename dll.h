#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>

class dll {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice, rectTest, rectTest2;


        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;

        // INTRO
        char str[80];


    public:
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);

        int load() ;

        void update(sf::RenderWindow &window);

        //INTRO
        void initIntro(sf::RenderWindow &window);
        void drawIntro(sf::RenderWindow &window);

        void initInterface(sf::RenderWindow &window);
        void drawInterface(sf::RenderWindow &window);
        void initInterface2(sf::RenderWindow &window);
        void drawInterface2(sf::RenderWindow &window);
};



#endif // DLL_H
