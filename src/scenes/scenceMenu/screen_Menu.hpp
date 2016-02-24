#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "../dll.h"

namespace screenMenu{
    class screen_Menu : public cScreen{
        private:
        public:
            screen_Menu(void);
            virtual int Run(sf::RenderWindow &App);
    };

}

using namespace screenMenu;

screen_Menu::screen_Menu(void){

}

int screen_Menu::Run(sf::RenderWindow &App){
    sf::Event Event;
    bool running = true;

    dll d;

    d.initMainMenu(App);
    while (running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }

<<<<<<< HEAD

=======
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
           /*if (Event.type == sf::Event::Resized){
                // on met à jour la vue, avec la nouvelle taille de la fenêtre
                sf::FloatRect visibleArea(0, 0, Event.size.width, Event.size.height);
                App.setView(sf::View(visibleArea));
                d.initMainMenu(App);
            }*/
        }




<<<<<<< HEAD
d.update(App);
=======

>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343


        App.clear(sf::Color(176,196,222));
        d.draw(App);
        App.display();
    }

    return -1;
}
