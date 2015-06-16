#include <iostream>
#include <SFML/Graphics.hpp>

class InfoBox : public sf::RectangleShape {
    private:
        sf::RectangleShape barSubWindowRect;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;
        float thickness;
        sf::Color thicknessColor;
    public:
        InfoBox(void);
        InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, sf::RenderWindow &window);
        virtual ~InfoBox(void);
        /*void setSize(const sf::Vector2f &size);
        sf::Vector2f getSize() const;
        void setPosition(const sf::Vector2f &position);
        sf::Vector2f getPosition() const;
        void setColor(const sf::Color &color);
        sf::Color getColor() const;
        void setThickness(float thickness);
        float getThickness() const;
        void setThicknessColor(const sf::Color &thicknessColor);
        sf::Color getThicknessColor() const;*/
        void draw(sf::RenderWindow &window);
};

InfoBox::InfoBox(void) {

}


InfoBox::InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, sf::RenderWindow &window) {
    //setOrigin(size/2.f);
    setSize(size);
    setPosition(position);
    setFillColor(color);
    setOutlineThickness(thickness);
    setOutlineColor(thicknessColor);

    barSubWindowRect.setSize(sf::Vector2f(294, 25));
    barSubWindowRect.setPosition(sf::Vector2f(103, 103));
    barSubWindowRect.setFillColor(sf::Color(0,0,0));
    window.draw(barSubWindowRect);
    draw(window);
}

InfoBox::~InfoBox(void) {

}
/*
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
}*/

void InfoBox::draw(sf::RenderWindow &window){
    window.draw(barSubWindowRect);
}
