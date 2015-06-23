#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

class Content : public sf::RectangleShape, public sf::Text, public sf::CircleShape{
    private:
        int number;
        bool clickable;
    public:
        Content(void);
        void setNumber(const int number);
        int getNumber() const;
        void setClickable(bool clickable);
        bool getClickable();
};

Content::Content(void) {
}

void Content::setNumber(const int number){
    this->number = number;
}

int Content::getNumber() const{
    return this->number;
}

void Content::setClickable(bool clickable){
    this->clickable = clickable;
}

bool Content::getClickable(){
    return this->clickable;
}
