#ifndef DLL_H
#define DLL_H
#include <SFML/Graphics.hpp>

class dll {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice;
<<<<<<< HEAD

        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;

        // INTRO
        char str[80];
=======
        sf::Font font;
sf::Texture textureFolder, textureClose;

>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
    public:
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);
        int load() ;
<<<<<<< HEAD
        void update(sf::RenderWindow &window);

        //INTRO
        void initIntro(sf::RenderWindow &window);
        void drawIntro(sf::RenderWindow &window);
=======

>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
};



#endif // DLL_H
