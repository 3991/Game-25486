#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>


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


    while (running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }
        }







        App.clear(sf::Color(255, 255, 255, 255));

        App.display();
    }

    return -1;
}
