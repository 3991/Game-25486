#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyRectangleShape.hpp"
#include <list>

class InfoBox {
    private:
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Font font;
        sf::Color color;
        float thickness;
        sf::Color thicknessColor;
        std::list<sf::RectangleShape> listShapes;
        std::list<sf::CircleShape> listCircles;
        std::list<sf::Text> listTexts;
        MyRectangleShape pane, paneBar, shape;
        sf::CircleShape circleShape;
        sf::Text text;
        int number;
    public:
        InfoBox(void);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number);
        virtual ~InfoBox(void);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        void setNumber(const int number);
        int getNumber() const;
};

InfoBox::InfoBox(void) {
}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color) {
    pane.setSize(size);
    pane.sf::RectangleShape::setPosition(position);
    pane.setFillColor(color);

    listShapes.push_front(pane);
}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number) {
    setNumber(number);
    pane.setSize(size);
    pane.sf::RectangleShape::setPosition(position);
    pane.setFillColor(color);
    pane.setOutlineThickness(thickness);
    pane.setOutlineColor(thicknessColor);

    paneBar.setSize(sf::Vector2f(294, 25));
    paneBar.sf::RectangleShape::setPosition(sf::Vector2f(103, 103));
    paneBar.setFillColor(sf::Color(0,0,0));

    listShapes.push_front(paneBar);
    listShapes.push_front(pane);
}

InfoBox::~InfoBox(void) {

}

void InfoBox::draw(sf::RenderWindow &window){
    for(std::list<sf::RectangleShape>::iterator inte = listShapes.begin(); inte != listShapes.end(); inte++){
        window.draw(*inte);
    }

    for(std::list<sf::Text>::iterator inte = listTexts.begin(); inte != listTexts.end(); inte++){
        window.draw(*inte);
   }

    for(std::list<sf::CircleShape>::iterator inte = listCircles.begin(); inte != listCircles.end(); inte++){
        window.draw(*inte);
   }
}

void InfoBox::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number){
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setString(message);
    text.setColor(color);
    text.setPosition(size);

    listTexts.push_front(text);
}

void InfoBox::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    shape.setSize(size);
    shape.sf::RectangleShape::setPosition(position);
    shape.setFillColor(color);
    shape.setOutlineThickness(thickness);
    shape.setOutlineColor(thicknessColor);

    listShapes.push_back(shape);
}

void InfoBox::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    circleShape.setRadius(radius);
    circleShape.setPosition(position);
    circleShape.setFillColor(color);
    circleShape.setOutlineThickness(thickness);
    circleShape.setOutlineColor(thicknessColor);

    listCircles.push_front(circleShape);
}

void InfoBox::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor){
    circleShape.setRadius(radius);
    circleShape.setPointCount(pointCount);
    circleShape.setPosition(position);
    circleShape.setFillColor(color);
    circleShape.setOutlineThickness(thickness);
    circleShape.setOutlineColor(thicknessColor);

    listCircles.push_front(circleShape);
}

void InfoBox::setNumber(const int number){
    this->number = number;
}

int InfoBox::getNumber() const{
    return this->number;
}
