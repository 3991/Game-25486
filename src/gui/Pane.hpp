#include <iostream>
#include <SFML/Graphics.hpp>
#include "Content.hpp"
#include <list>

class Pane {
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
        Pane(void);
        explicit Pane(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
        explicit Pane(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number);
        virtual ~Pane(void);
        void draw(sf::RenderWindow &window);
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, bool clickable);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable);
        void setNumber(const int number);
        int getNumber() const;
        std::list<Content> getTexts() const;
        std::list<Content> getCircles() const;
        std::list<Content> getShapes() const;
        void resetFamilysColors(sf::Color color);
        void setColor(const int &id, sf::Color color);
};

Pane::Pane(void) {
}

Pane::Pane(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color) {
    pane.sf::RectangleShape::setSize(size);
    pane.sf::RectangleShape::setPosition(position);
    pane.sf::RectangleShape::setFillColor(color);

    shapes.push_front(pane);
}

Pane::Pane(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int number) {
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

Pane::~Pane(void) {

}

void Pane::draw(sf::RenderWindow &window){
    for(std::list<Content>::iterator inte = shapes.begin(); inte != shapes.end(); inte++){
        window.draw((sf::RectangleShape)*inte);
    }

    for(std::list<Content>::iterator inte = circles.begin(); inte != circles.end(); inte++){
        window.draw((sf::CircleShape)*inte);
    }
    /*Important afficher texts en dernier pour passer sur la forme*/
    for(std::list<Content>::iterator inte = texts.begin(); inte != texts.end(); inte++){
        window.draw((sf::Text)*inte);
    }
}

void Pane::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, bool clickable){
    text.setNumber(number);
    text.sf::Text::setFont(font);
    text.sf::Text::setCharacterSize(fontSize);
    text.sf::Text::setString(message);
    text.sf::Text::setColor(color);
    text.sf::Text::setPosition(size);
    text.setClickable(clickable);

    texts.push_front(text);
}

void Pane::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable){
    shape.setNumber(number);
    shape.sf::RectangleShape::setSize(size);
    shape.sf::RectangleShape::setPosition(position);
    shape.sf::RectangleShape::setFillColor(color);
    shape.sf::RectangleShape::setOutlineThickness(thickness);
    shape.sf::RectangleShape::setOutlineColor(thicknessColor);
    shape.setClickable(clickable);

    shapes.push_back(shape);
}

void Pane::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable){
    circleShape.setNumber(number);
    circleShape.sf::CircleShape::setRadius(radius);
    circleShape.sf::CircleShape::setPosition(position);
    circleShape.sf::CircleShape::setFillColor(color);
    circleShape.sf::CircleShape::setOutlineThickness(thickness);
    circleShape.sf::CircleShape::setOutlineColor(thicknessColor);
    circleShape.setClickable(clickable);

    circles.push_front(circleShape);
}

void Pane::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, bool clickable){
    circleShape.setNumber(number);
    circleShape.sf::CircleShape::setRadius(radius);
    circleShape.sf::CircleShape::setPointCount(pointCount);
    circleShape.sf::CircleShape::setPosition(position);
    circleShape.sf::CircleShape::setFillColor(color);
    circleShape.sf::CircleShape::setOutlineThickness(thickness);
    circleShape.sf::CircleShape::setOutlineColor(thicknessColor);
    circleShape.setClickable(clickable);

    circles.push_front(circleShape);
}

void Pane::setNumber(const int number){
    this->number = number;
}

int Pane::getNumber() const{
    return this->number;
}

std::list<Content> Pane::getTexts() const{
    return this->texts;
}

std::list<Content> Pane::getShapes() const{
    return this->shapes;
}

std::list<Content> Pane::getCircles() const{
    return this->circles;
}

void Pane::resetFamilysColors(sf::Color color){
    for(std::list<Content>::iterator inte = shapes.begin(); inte != shapes.end(); inte++){
        if(inte->getClickable()){
            inte->sf::RectangleShape::setOutlineColor(color);
            inte->sf::RectangleShape::setOutlineThickness(2);
        }
    }

    for(std::list<Content>::iterator inte = texts.begin(); inte != texts.end(); inte++){
        if(inte->getClickable()){
            inte->sf::Text::setColor(color);
        }
    }

    for(std::list<Content>::iterator inte = circles.begin(); inte != circles.end(); inte++){
        if(inte->getClickable()){
            inte->sf::CircleShape::setOutlineColor(color);
            inte->sf::CircleShape::setOutlineThickness(2);
        }
    }
}

void Pane::setColor(const int &id, sf::Color color){
    bool see = false;
    for(std::list<Content>::iterator inte = shapes.begin(); inte != shapes.end(); inte++){
        if(inte->getClickable()){
            if(inte->getNumber() == id){
                inte->sf::RectangleShape::setOutlineColor(color);
                inte->sf::RectangleShape::setOutlineThickness(5);
                see = true;
                break;
            }
        }
    }

    if(!see){
        for(std::list<Content>::iterator inte = texts.begin(); inte != texts.end(); inte++){
            if(inte->getClickable()){
                if(inte->getNumber() == id){
                    inte->sf::Text::setColor(color);
                    see = true;
                    break;
                }
            }
        }
    }

    if(!see){
        for(std::list<Content>::iterator inte = circles.begin(); inte != circles.end(); inte++){
            if(inte->getClickable()){
                if(inte->getNumber() == id){
                    inte->sf::CircleShape::setOutlineColor(color);
                    inte->sf::CircleShape::setOutlineThickness(5);
                    break;
                }
            }
        }
    }

}
