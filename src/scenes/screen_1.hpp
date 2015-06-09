#include <iostream>
#include "cScreen.hpp"
#include <SFML/Graphics.hpp>
#define SPEED 7
class screen_1 : public cScreen
{
private:
    sf::RectangleShape rectangle, menuBarRect, builduingRect;
    sf::Text buildingText, createBuildingText, destroyBuildingText, modifyBuildingText;
    sf::Font font;
public:
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
    int load();
};

screen_1::screen_1(void){
    rectangle.setOutlineThickness(3);
    rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
    rectangle.setSize({ 50.f, 50.f });
}

int screen_1::Run(sf::RenderWindow &App){
    sf::Event Event;
    bool Running = true, test = false;

    load();

    menuBarRect.setSize((sf::Vector2f(800, 30)));
    menuBarRect.setPosition(sf::Vector2f(0, 0));
    menuBarRect.setFillColor(sf::Color(237, 237, 237));


    builduingRect.setSize(sf::Vector2f(100, 300));
    builduingRect.setPosition(sf::Vector2f(5, 5));
    builduingRect.setFillColor(sf::Color(220, 220, 220));
    //builduingRect.setOutlineThickness(1);
    //builduingRect.setOutlineColor(sf::Color(49, 140, 231));

    buildingText.setFont(font);
    buildingText.setCharacterSize(18);
    buildingText.setString("Building");
    buildingText.setPosition({ 10.f, 5.f });
    buildingText.setColor(sf::Color::Black);

    createBuildingText.setFont(font);
    createBuildingText.setCharacterSize(18);
    createBuildingText.setString("Create");
    createBuildingText.setPosition({ 10.f, 25.f });
    createBuildingText.setColor(sf::Color::Black);

    sf::FloatRect builduigTextDetection(buildingText.getPosition().x, buildingText.getPosition().y, buildingText.getGlobalBounds().width, buildingText.getGlobalBounds().height);

    while (Running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                rectangle.move(-SPEED, 0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                rectangle.move(+SPEED,0);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                rectangle.move(0,-SPEED);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                rectangle.move(0,+SPEED);
            }


            if(builduigTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
                test = true;
            }else{
                test = false;
            }
        }

        App.clear(sf::Color(255, 255, 255, 255));
        App.draw(rectangle);
        App.draw(menuBarRect);

        if(test){
           App.draw(builduingRect);
           App.draw(createBuildingText);
        }

        App.draw(buildingText);

        App.display();
    }

    return -1;
}

int screen_1::load() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    return 0;
}
