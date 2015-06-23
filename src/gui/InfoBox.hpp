#include <iostream>
#include <SFML/Graphics.hpp>
#include "Content.hpp"
#include <list>

class InfoBox {
    private:
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Font font;
        sf::Color color;
        float thickness;
        sf::Color thicknessColor;
        std::list<Content> shapes;
        std::list<Content> circles;
        std::list<Content> texts;
        Content pane, paneBar, shape, text, circleShape;
        int number;
    public:
        InfoBox(void);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number);
        virtual ~InfoBox(void);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number);
        void setNumber(const int number);
        int getNumber() const;
        std::list<Content> getTexts() const;
        std::list<Content> getCircles() const;
        std::list<Content> getShapes() const;
        Content getCircle(const int &id) const;
};

InfoBox::InfoBox(void) {
}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color) {
    pane.sf::RectangleShape::setSize(size);
    pane.sf::RectangleShape::setPosition(position);
    pane.sf::RectangleShape::setFillColor(color);

    shapes.push_front(pane);
}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number) {
    setNumber(number);
    pane.sf::RectangleShape::setSize(size);
    pane.sf::RectangleShape::setPosition(position);
    pane.sf::RectangleShape::setFillColor(color);
    pane.sf::RectangleShape::setOutlineThickness(thickness);
    pane.sf::RectangleShape::setOutlineColor(thicknessColor);

    paneBar.sf::RectangleShape::setSize(sf::Vector2f(294, 25));
    paneBar.sf::RectangleShape::setPosition(sf::Vector2f(103, 103));
    paneBar.sf::RectangleShape::setFillColor(sf::Color(0,0,0));

    shapes.push_front(paneBar);
    shapes.push_front(pane);
}

InfoBox::~InfoBox(void) {

}

void InfoBox::draw(sf::RenderWindow &window){
    for(std::list<Content>::iterator inte = shapes.begin(); inte != shapes.end(); inte++){
        window.draw((sf::RectangleShape)*inte);
    }

    for(std::list<Content>::iterator inte = texts.begin(); inte != texts.end(); inte++){
        window.draw((sf::Text)*inte);
    }

    for(std::list<Content>::iterator inte = circles.begin(); inte != circles.end(); inte++){
        window.draw((sf::CircleShape)*inte);
    }
}

void InfoBox::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number){
    text.setNumber(number);
    text.sf::Text::setFont(font);
    text.sf::Text::setCharacterSize(fontSize);
    text.sf::Text::setString(message);
    text.sf::Text::setColor(color);
    text.sf::Text::setPosition(size);

    texts.push_front(text);
}

void InfoBox::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number){
    shape.setNumber(number);
    shape.sf::RectangleShape::setSize(size);
    shape.sf::RectangleShape::setPosition(position);
    shape.sf::RectangleShape::setFillColor(color);
    shape.sf::RectangleShape::setOutlineThickness(thickness);
    shape.sf::RectangleShape::setOutlineColor(thicknessColor);

    shapes.push_back(shape);
}

void InfoBox::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number){
    circleShape.setNumber(number);
    circleShape.sf::CircleShape::setRadius(radius);
    circleShape.sf::CircleShape::setPosition(position);
    circleShape.sf::CircleShape::setFillColor(color);
    circleShape.sf::CircleShape::setOutlineThickness(thickness);
    circleShape.sf::CircleShape::setOutlineColor(thicknessColor);

    circles.push_front(circleShape);
}

void InfoBox::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number){
    circleShape.setNumber(number);
    circleShape.sf::CircleShape::setRadius(radius);
    circleShape.sf::CircleShape::setPointCount(pointCount);
    circleShape.sf::CircleShape::setPosition(position);
    circleShape.sf::CircleShape::setFillColor(color);
    circleShape.sf::CircleShape::setOutlineThickness(thickness);
    circleShape.sf::CircleShape::setOutlineColor(thicknessColor);

    circles.push_front(circleShape);
}

void InfoBox::setNumber(const int number){
    this->number = number;
}

int InfoBox::getNumber() const{
    return this->number;
}

std::list<Content> InfoBox::getTexts() const{
    return this->texts;
}

std::list<Content> InfoBox::getShapes() const{
    return this->shapes;
}

std::list<Content> InfoBox::getCircles() const{
    return this->circles;
}

Content InfoBox::getCircle(const int &id) const{
    Content c;
   // for(std::list<Content>::iterator inte = circles.begin(); inte != circles.end(); inte++){
        //if(inte->getNumber() == id){
           // return inte;
        //}
   //}
    return c;
}
