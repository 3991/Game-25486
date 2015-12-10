#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#define FONT_SIZE 18

class Player {
    private:

    public:
        Player(void);
};

Player::Player(void) {
}

void Player::up(float frame){

    rect_player.move(0, -SPEED*frame);
}

void Player::down(float frame){

    rect_player.move(0, SPEED*frame);
}

void Player::left(float frame){

    rect_player.move(-SPEED*frame, 0);
}

void Player::right(float frame){

    rect_player.move(SPEED*frame, 0);
}

void Player::display(sf::RenderWindow &window){


    window.draw(rect_player);
}

void Player::setX(int x){

    this->x = x;
}

void Player::setY(int y){

    this->y = y;
}

int Player::getX() const{

    return this->x;
}

int Player::getY() const{

    return this->y;
}
