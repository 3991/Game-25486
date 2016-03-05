#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>
#include "./gui/Presentation.hpp"


namespace screenIntro{
    class screen_Intro : public cScreen{
        private:
        public:
            screen_Intro(void);
            virtual int Run(sf::RenderWindow &App);
    };

}

using namespace screenIntro;

screen_Intro::screen_Intro(void){

}

int screen_Intro::Run(sf::RenderWindow &App){
    sf::Event Event;
    bool running = true;

    Presentation present;
    present.initIntro(App);

    while (running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                return (2);
            }
        }




        App.clear(sf::Color(0,0,0));
        present.drawIntro(App);
        App.display();
    }

    return -1;
}
