#include <iostream>
#include <SFML/Graphics.hpp>

class InfoBox : public sf::RectangleShape {
    private:
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;
        float thickness;
        sf::Color thicknessColor;
    public:
        InfoBox(void);
        InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
        InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        virtual ~InfoBox(void);
        void setSize(const sf::Vector2f &size);
        sf::Vector2f getSize() const;
        void setPosition(const sf::Vector2f &position);
        sf::Vector2f getPosition() const;
        void setColor(const sf::Color &color);
        sf::Color getColor() const;
        void setThickness(float thickness);
        float getThickness() const;
        void setThicknessColor(const sf::Color &thicknessColor);
        sf::Color getThicknessColor() const;
        void draw(sf::RenderWindow &window);
};

InfoBox::InfoBox(void) {

}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color) {
    this->shape.setSize(size);
    this->shape.setPosition(position);
    this->shape.setFillColor(color);
}

InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor) {
    this->shape.setSize(size);
    this->shape.setPosition(position);
    this->shape.setFillColor(color);
    this->shape.setOutlineThickness(thickness);
    this->shape.setOutlineColor(thicknessColor);
}

InfoBox::~InfoBox(void) {

}

void InfoBox::setSize(const sf::Vector2f &size){
    this->size = size;
}

sf::Vector2f InfoBox::getSize() const{
    return this->size;
}

void InfoBox::setPosition(const sf::Vector2f &position){
    this->position = position;
}

sf::Vector2f InfoBox::getPosition() const{
    return this->position;
}

void InfoBox::setColor(const sf::Color &color){
    this->color = color;
}

sf::Color InfoBox::getColor() const{
    return this->color;
}

void InfoBox::setThickness(float thickness){
    this->setOutlineThickness(thickness);
}

float InfoBox::getThickness() const{
    return this->thickness;
}

void InfoBox::setThicknessColor(const sf::Color &thicknessColor){
    this->setOutlineColor(thicknessColor);
}

sf::Color InfoBox::getThicknessColor() const{
    return this->thicknessColor;
}

void InfoBox::draw(sf::RenderWindow &window){
    window.draw(this->shape);
}
