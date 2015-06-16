#include <iostream>
#include <SFML/Graphics.hpp>

class ManagerGUI {
    private:
        InfoBox subWindowRect;
    public:
        ManagerGUI(void);
        void ManagerGUI::addSubwindow();
};

ManagerGUI::ManagerGUI(void) {
}


void ManagerGUI::addSubwindow(){
    subWindowRect = InfoBox(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), App);

}
