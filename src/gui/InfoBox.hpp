#include <iostream>
#include <SFML/Graphics.hpp>

class InfoBox : public sf::Shape {
    public :
        //explicit InfoBox(const sf::Vector2f& radius = sf::Vector2f(0, 0));
        InfoBox(void);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
        explicit InfoBox(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor);
        //void setRadius(const sf::Vector2f& radius);
        //const sf::Vector2f& getRadius() const;
        virtual unsigned int getPointCount() const;
        virtual sf::Vector2f getPoint(unsigned int index) const;

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
    private :
        sf::Vector2f m_radius;
                sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color color;
        float thickness;
        sf::Color thicknessColor;
};

/*InfoBox::InfoBox(const sf::Vector2f& radius = sf::Vector2f(0, 0)) : m_radius(radius) {
    update();
}*/

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

/*void setRadius(const sf::Vector2f& radius) {
    m_radius = radius;
    update();
}

const sf::Vector2f& getRadius() const {
    return m_radius;
}*/

unsigned int InfoBox::getPointCount() const {
    return 30; // fixé, mais ça pourrait tout aussi bien être un attribut de la classe
}

sf::Vector2f InfoBox::getPoint(unsigned int index) const {
    /*static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;*/

    return sf::Vector2f(0, 0);
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
