#include <iostream>
#include <SFML/Graphics.hpp>


class ManagerGUI {
    private:
        Pane pane;
        std::vector<Pane*> windowList;
    public:
        ManagerGUI(void);
        virtual ~ManagerGUI(void);
        void addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane, bool clickable);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        std::list<Content> getTexts(const int &idPane);
        std::list<Content> getShapes(const int &idPane);
        std::list<Content> getCircles(const int &idPane);
        int getPaneIndex(const int &id);
        void resetFamilysColors(const int &idPane, sf::Color color);
        void setColor(const int &idPane, const int &id, sf::Color color);
};

ManagerGUI::ManagerGUI(void) {
}


ManagerGUI::~ManagerGUI(void) {
}

void ManagerGUI::addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number){
    pane = Pane(size, position, color, thickness, thicknessColor, number);
    windowList.push_back(&pane);
}

void ManagerGUI::draw(sf::RenderWindow &window){
    for(unsigned int a = 0;a<windowList.size(); a++){
        windowList[a]->draw(window);
    }
}

void ManagerGUI::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addText(font, fontSize, message, color, size, number, clickable);
}

void ManagerGUI::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(size, position, color, thickness, thicknessColor, number, clickable);
}

void ManagerGUI::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, position, color, thickness, thicknessColor, number, clickable);
}

void ManagerGUI::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, pointCount, position, color, thickness, thicknessColor, number, clickable);
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

void ManagerGUI::resetFamilysColors(const int &idPane, sf::Color color){
    int index = getPaneIndex(idPane);
    return windowList[index]->resetFamilysColors(color);
}

void ManagerGUI::setColor(const int &idPane, const int &id, sf::Color color){
    int index = getPaneIndex(idPane);
    return windowList[index]->setColor(id, color);
}
