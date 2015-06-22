#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

class Content : public sf::RectangleShape, public sf::Text, public sf::CircleShape{
    private:
        int number;
    public:
        Content(void);
        void setNumber(const int number);
        int getNumber() const;
};

Content::Content(void) {
}

void Content::setNumber(const int number){
    this->number = number;
}

int Content::getNumber() const{
    return this->number;
}
