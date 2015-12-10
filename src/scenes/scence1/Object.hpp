#include <iostream>
#include "./../cScreen.hpp"
#include <SFML/Graphics.hpp>


class Object {
    private:
        int pollution, lifetime, health, love, sleep, safety;
    public:
        Object(void);
        void setPollution(int pollution);
        void setLifetime(int lifetime);
        void setHealth(int health);
        void setLove(int love);
        void setSleep(int sleep);
        void setSafety(int safety);
        int getPollution() const;
        int getLifetime() const;
        int getHealth() const;
        int getLove() const;
        int getSleep() const;
        int getSafety() const;
};

Object::Object(void) {
    setPollution(0);
    setLifetime(0);
    setHealth(0);
    setLove(0);
    setSleep(0);
    setSafety(0);
}

void Object::setPollution(int pollution){

    this->pollution = pollution;
}

void Object::setLifetime(int lifetime){

    this->lifetime = lifetime;
}

void Object::setHealth(int health){

    this->health = health;
}

void Object::setLove(int love){

    this->love = love;
}

void Object::setSleep(int sleep){

    this->sleep = sleep;
}

void Object::setSafety(int safety){

    this->safety = safety;
}

int Object::getPollution() const{

    return this->pollution;
}

int Object::getLifetime() const{

    return this->lifetime;
}

int Object::getHealth() const{

    return this->health;
}

int Object::getLove() const{

    return this->love;
}

int Object::getSleep() const{

    return this->sleep;
}

int Object::getSafety() const{

    return this->safety;
}
