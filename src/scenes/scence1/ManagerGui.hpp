#include <iostream>
#include <SFML/Graphics.hpp>

class ManagerGui {
    private:
        Pane pane;
        std::vector<Pane*> windowList;
    public:
        ManagerGui(void);
        virtual ~ManagerGui(void);
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
        void drawLines(sf::RenderWindow &window, sf::ConvexShape lines);
        void setText(sf::String &message, const int &number, const int &idPane);
};

ManagerGui::ManagerGui(void) {
}


ManagerGui::~ManagerGui(void) {
}

void ManagerGui::addSubwindow(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, int number){
    pane = Pane(size, position, color, thickness, thicknessColor, number);
    windowList.push_back(&pane);
}

void ManagerGui::draw(sf::RenderWindow &window){
    for(unsigned int a = 0;a<windowList.size(); a++){
        windowList[a]->draw(window);
    }
}

void ManagerGui::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addText(font, fontSize, message, color, size, number, clickable);
}

void ManagerGui::setText(sf::String &message, const int &number, const int &idPane){
    int index = getPaneIndex(idPane);
    windowList[index]->setText(number, message);
}

void ManagerGui::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(size, position, color, thickness, thicknessColor, number, clickable);
}

void ManagerGui::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, position, color, thickness, thicknessColor, number, clickable);
}

void ManagerGui::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    int index = getPaneIndex(idPane);
    windowList[index]->addShape(radius, pointCount, position, color, thickness, thicknessColor, number, clickable);
}

std::list<Content> ManagerGui::getTexts(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getTexts();
}

std::list<Content> ManagerGui::getShapes(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getShapes();
}

std::list<Content> ManagerGui::getCircles(const int &idPane){
    int index = getPaneIndex(idPane);
    return windowList[index]->getCircles();
}

int ManagerGui::getPaneIndex(const int &idPane){
    for(unsigned int a = 0;a<windowList.size(); a++){
        if(windowList[a]->getNumber() == idPane){
           return a;
        }
    }
    return -1;
}

void ManagerGui::drawLines(sf::RenderWindow &window, sf::ConvexShape lines){
    window.draw(lines);
    //window.draw(&vertices[0], vertices.size(), sf::Lines);
}

void ManagerGui::resetFamilysColors(const int &idPane, sf::Color color){
    int index = getPaneIndex(idPane);
    return windowList[index]->resetFamilysColors(color);
}

void ManagerGui::setColor(const int &idPane, const int &id, sf::Color color){
    int index = getPaneIndex(idPane);
    return windowList[index]->setColor(id, color);
}
