#include <iostream>
#include "cScreen.hpp"
#include "../gui/InfoBox.hpp"
#include <SFML/Graphics.hpp>


namespace screen0
{
class screen_0 : public cScreen {
    private:
        sf::Font font;
        sf::Text text, tileSubWindowText, nameMenuText, familyMenuText, choiceSubTitleText, continueSubWindowText, quitSubWindowText;
        InfoBox subWindowRect;
        sf::RectangleShape barSubWindowRect;
        sf::RectangleShape textAreaRect;
        sf::CircleShape circle;
        sf::CircleShape triangle;
        sf::CircleShape square;
        sf::RectangleShape rectangle;
        sf::CircleShape hexagon;
        sf::CircleShape pentagon;
        InfoBox tests;
    public:
        screen_0(void);
        virtual int Run(sf::RenderWindow &App);
        int load();
        void initText();
        void initShape();
};
const int fontSize = 18;
}

using namespace screen0;

screen_0::screen_0(void) {
     //subWindowRect = InfoBox(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0));

}




int screen_0::Run(sf::RenderWindow &App) {
    sf::Event Event;
    bool running = true;

    sf::String textes;
    bool typeOn = false;

    load();

    initText();
    initShape();

    // Detection area
    sf::FloatRect textAreaDetection(textAreaRect.getPosition().x, textAreaRect.getPosition().y, textAreaRect.getSize().x, textAreaRect.getSize().y);
    sf::FloatRect circleDetection(circle.getPosition().x, circle.getPosition().y, circle.getLocalBounds().width , circle.getLocalBounds().width);
    sf::FloatRect triangleDetection(triangle.getPosition().x, triangle.getPosition().y, triangle.getLocalBounds().width, triangle.getLocalBounds().width);
    sf::FloatRect squareDetection(square.getPosition().x, square.getPosition().y, square.getLocalBounds().width, square.getLocalBounds().width);
    sf::FloatRect rectangleDetection(rectangle.getPosition().x, rectangle.getPosition().y, rectangle.getSize().x, rectangle.getSize().y);
    sf::FloatRect hexagonDetection(hexagon.getPosition().x, hexagon.getPosition().y, hexagon.getLocalBounds().width, hexagon.getLocalBounds().width);
    sf::FloatRect pentagonDetection(pentagon.getPosition().x, pentagon.getPosition().y, pentagon.getLocalBounds().width, pentagon.getLocalBounds().width);
    sf::FloatRect continueTextDetectionDetection(continueSubWindowText.getPosition().x, continueSubWindowText.getPosition().y, continueSubWindowText.getGlobalBounds().width, continueSubWindowText.getGlobalBounds().height);
    sf::FloatRect quitTextDetectionDetection(quitSubWindowText.getPosition().x, quitSubWindowText.getPosition().y, quitSubWindowText.getGlobalBounds().width, quitSubWindowText.getGlobalBounds().height);


    while (running) {
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }

            // Collision detection
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && textAreaDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
                typeOn = true;
                textAreaRect.setOutlineColor(sf::Color(255, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && circleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(255, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && triangleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(255, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && squareDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(255, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && rectangleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(255, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && hexagonDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(255, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && pentagonDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                typeOn = false;
                textAreaRect.setOutlineColor(sf::Color(0, 0, 0));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(255, 0, 0));
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && continueTextDetectionDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                return (1);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && quitTextDetectionDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                return (-1);
            }

            if(continueTextDetectionDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color(16, 52, 166, 255));
                quitSubWindowText.setColor(sf::Color::Black);
            }else if(quitTextDetectionDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color(16, 52, 166, 255));
            }

            if(typeOn){
               if (Event.type == sf::Event::TextEntered){
                   if (Event.text.unicode < 128){
                        textes += Event.text.unicode;
                        text.setString(textes);
                   }
                }
            }


          /*  if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                        //menu = 0;
                        break;
                    case sf::Keyboard::Down:
                        //menu = 1;
                        break;
                    default:
                        break;
                }
            }*/



        }


        /*if (menu == 0) {
            nameMenuText.setColor(sf::Color(16, 52, 166, 255));
            familyMenuText.setColor(sf::Color(0, 0, 0, 255));
        }else {
            nameMenuText.setColor(sf::Color(0, 0, 0, 255));
            familyMenuText.setColor(sf::Color(16, 52, 166, 255));
        }*/


        App.clear(sf::Color(255, 255, 255, 255));
        App.draw(subWindowRect);
        App.draw(barSubWindowRect);
        App.draw(textAreaRect);
subWindowRect.draw(App);
        App.draw(choiceSubTitleText);
        App.draw(tileSubWindowText);
        App.draw(nameMenuText);
        App.draw(familyMenuText);
        App.draw(quitSubWindowText);
        App.draw(continueSubWindowText);

        App.draw(circle);
        App.draw(triangle);
        App.draw(square);
        App.draw(rectangle);
        App.draw(hexagon);
        App.draw(pentagon);

        App.draw(text);
        App.display();
    }

    return (-1);
}


int screen_0::load() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    return 0;
}


void screen_0::initText() {
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setColor(sf::Color::Black);
    text.setPosition(125, 190);

    tileSubWindowText.setFont(font);
    tileSubWindowText.setCharacterSize(fontSize);
    tileSubWindowText.setString("Birth-certificate");
    tileSubWindowText.setPosition({ 105.f, 105.f });

    continueSubWindowText.setFont(font);
    continueSubWindowText.setCharacterSize(fontSize);
    continueSubWindowText.setString("Continue");
    continueSubWindowText.setColor(sf::Color::Black);
    continueSubWindowText.setPosition({ 200.f, 470.f });

    quitSubWindowText.setFont(font);
    quitSubWindowText.setCharacterSize(fontSize);
    quitSubWindowText.setString("Quit");
    quitSubWindowText.setColor(sf::Color::Black);
    quitSubWindowText.setPosition({ 200.f, 490.f });

    nameMenuText.setColor(sf::Color(0, 0, 0, 255));
    nameMenuText.setFont(font);
    nameMenuText.setCharacterSize(fontSize);
    nameMenuText.setString("1. What's your name ?");
    nameMenuText.setPosition({ 170.f, 160.f });

    familyMenuText.setColor(sf::Color(0, 0, 0, 255));
    familyMenuText.setFont(font);
    familyMenuText.setCharacterSize(fontSize);
    familyMenuText.setString("2. What's your family ?");
    familyMenuText.setPosition({ 170.f, 270.f });

    choiceSubTitleText.setFont(font);
    choiceSubTitleText.setCharacterSize(fontSize);
    choiceSubTitleText.setColor(sf::Color::Black);
    choiceSubTitleText.setString("3. Now make a choice");
    choiceSubTitleText.setPosition({ 170.f, 450.f });

    textAreaRect.setSize((sf::Vector2f(250, 25)));
    textAreaRect.setPosition(sf::Vector2f(120, 185));
    textAreaRect.setFillColor(sf::Color(255, 255, 255, 255));
    textAreaRect.setOutlineThickness(2);
    textAreaRect.setOutlineColor(sf::Color(0, 0, 0));
}

void screen_0::initShape() {
    //subWindowRect = InfoBox(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0));
    subWindowRect.setSize((sf::Vector2f(300, 450)));
    subWindowRect.setPosition(sf::Vector2f(100, 100));
    subWindowRect.setFillColor(sf::Color(237, 237, 237));
    subWindowRect.setOutlineThickness(3);
    subWindowRect.setOutlineColor(sf::Color(0, 0, 0));

    barSubWindowRect.setSize((sf::Vector2f(294, 25)));
    barSubWindowRect.setPosition(sf::Vector2f(103, 103));
    barSubWindowRect.setFillColor(sf::Color(0, 0, 0));


    circle.setRadius(25);
    circle.setPosition(sf::Vector2f(120, 300));
    circle.setFillColor(sf::Color(255, 255, 255, 255));
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color(0, 0, 0));

    //triangle.setPointCount(30, 3);
    triangle.setRadius(30);
    triangle.setPointCount(3);
    triangle.setPosition(sf::Vector2f(180, 300));
    triangle.setFillColor(sf::Color(255, 255, 255, 255));
    triangle.setOutlineThickness(2);
    triangle.setOutlineColor(sf::Color(0, 0, 0));

    //square.setPointCount(30, 4);
    square.setRadius(30);
    square.setPointCount(4);
    square.setPosition(sf::Vector2f(250, 300));
    square.setFillColor(sf::Color(255, 255, 255, 255));
    square.setOutlineThickness(2);
    square.setOutlineColor(sf::Color(0, 0, 0));

    rectangle.setSize((sf::Vector2f(70, 40)));
    rectangle.setPosition(sf::Vector2f(120, 390));
    rectangle.setFillColor(sf::Color(255, 255, 255, 255));
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color(0, 0, 0));

    //hexagon.setPointCount(30, 6);
    hexagon.setRadius(30);
    hexagon.setPointCount(6);
    hexagon.setPosition(sf::Vector2f(220, 380));
    hexagon.setFillColor(sf::Color(255, 255, 255, 255));
    hexagon.setOutlineThickness(2);
    hexagon.setOutlineColor(sf::Color(0, 0, 0));

    //pentagon.setPointCount(30, 5);
    pentagon.setRadius(30);
    pentagon.setPointCount(5);
    pentagon.setPosition(sf::Vector2f(290, 380));
    pentagon.setFillColor(sf::Color(255, 255, 255, 255));
    pentagon.setOutlineThickness(2);
    pentagon.setOutlineColor(sf::Color(0, 0, 0));
}
