#include <iostream>
#include <SFML/Graphics.hpp>

class ManagerGUI {
    private:
        InfoBox pane;
        std::vector<InfoBox*> windowList;
        int screen;
    public:
        ManagerGUI(void);
        virtual ~ManagerGUI(void);
        void addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
};

ManagerGUI::ManagerGUI(void) {
    screen = 0;
}


ManagerGUI::~ManagerGUI(void) {
}

void ManagerGUI::addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number){
    pane = InfoBox(size, position, color, thickness, thicknessColor, number);
    windowList.push_back(&pane);
}

void ManagerGUI::draw(sf::RenderWindow &window){
    //for(std::list<InfoBox>::iterator inte = windowList.begin(); inte != windowList.end(); inte++){
       //inte->draw(window);

   //}
   //for(int a = 0;a<windowList.size(); a++){

    windowList[0]->draw(window);

        //z = windowList[a];
        //z.draw(window);
    //}
   //pane.draw(window);
}

void ManagerGUI::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number){
    pane.addText(font, fontSize, message, color, size, number);
}

void ManagerGUI::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    pane.addShape(size, position, color, thickness, thicknessColor);
}

void ManagerGUI::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    pane.addShape(radius, position, color, thickness, thicknessColor);
}

void ManagerGUI::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    pane.addShape(radius, pointCount, position, color, thickness, thicknessColor);
}
