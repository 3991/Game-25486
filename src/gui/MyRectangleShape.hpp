#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

class MyRectangleShape : public sf::RectangleShape, public sf::Text{
    private:
        int number;
    public:
        MyRectangleShape(void);
        void setNumber(const int number);
        int getNumber() const;
};

MyRectangleShape::MyRectangleShape(void) {
}

void MyRectangleShape::setNumber(const int number){
    this->number = number;
}

int MyRectangleShape::getNumber() const{
    return this->number;
}
