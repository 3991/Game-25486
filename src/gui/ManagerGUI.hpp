#include <iostream>
#include <SFML/Graphics.hpp>

class ManagerGUI {
    private:
        InfoBox subWindowRect, barSubWindowRect;
    public:
        ManagerGUI(void);
        void ManagerGUI::addSubwindow();
        void draw(sf::RenderWindow &window);
};

ManagerGUI::ManagerGUI(void) {
}


void ManagerGUI::addSubwindow(){
    subWindowRect = InfoBox(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0));


    barSubWindowRect = InfoBox(sf::Vector2f(294, 25), sf::Vector2f(103, 103), sf::Color(0,0,0),);
}

void ManagerGUI::draw(sf::RenderWindow &window){
    window.draw(subWindowRect);
    window.draw(barSubWindowRect);
}
