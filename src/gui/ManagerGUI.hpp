#include <iostream>
#include <SFML/Graphics.hpp>

class ManagerGUI {
    private:
        InfoBox pane;
        std::vector<InfoBox*> windowList;
    public:
        ManagerGUI(void);
        virtual ~ManagerGUI(void);
        void addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane);
        std::list<Content> getTexts(const int &idPane);
        std::list<Content> getShapes(const int &idPane);
        std::list<Content> getCircles(const int &idPane);
        int getPaneIndex(const int &id);
};

ManagerGUI::ManagerGUI(void) {
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
    for(unsigned int a = 0;a<windowList.size(); a++){
        windowList[a]->draw(window);
    }
   //pane.draw(window);
}

void ManagerGUI::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane){
    pane.addText(font, fontSize, message, color, size, number);
}

void ManagerGUI::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(size, position, color, thickness, thicknessColor, number);
}

void ManagerGUI::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, position, color, thickness, thicknessColor, number);
}

void ManagerGUI::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, pointCount, position, color, thickness, thicknessColor, number);
}

std::list<Content> ManagerGUI::getTexts(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getTexts();
}

std::list<Content> ManagerGUI::getShapes(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getShapes();
}

std::list<Content> ManagerGUI::getCircles(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getCircles();
}

int ManagerGUI::getPaneIndex(const int &idPane){
    for(unsigned int a = 0;a<windowList.size(); a++){
        if(windowList[a]->getNumber() == idPane){
           return a;
        }
    }
    return -1;
}
