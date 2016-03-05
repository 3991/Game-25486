#include <iostream>
#include "../cScreen.hpp"
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Fps.hpp"
#include "./gui/Interface.hpp"

namespace screenMenu{
    class screen_Menu : public cScreen{
        private:
           // dll d;#include "../dll.h"
            Interface interf;
            Player player;
            Fps mainFps;
            float frame;
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

   // d.initInterface(App);
    interf.initInterface(App);

    while (running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }
        }



        /************************ Fps ************************/
        mainFps.calculate();



        frame = mainFps.getFrameTime();
        if(frame > 60){

            frame = 59;
        }

        mainFps.setX(0);
        mainFps.setY(0);






        player.update(frame);






        App.clear(sf::Color(176,196,222));
        //d.drawInterface(App);
        interf.drawInterface(App);
        player.display(App);
        mainFps.display(App);
        App.display();
    }

    return -1;
}
