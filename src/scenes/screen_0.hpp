#include <iostream>
#include "cScreen.hpp"
#include "../gui/InfoBox.hpp"
#include "../gui/ManagerGUI.hpp"
#include <SFML/Graphics.hpp>

namespace screen0
{
class screen_0 : public cScreen {
    private:
        sf::Font font;
        sf::Text text, tileSubWindowText, nameMenuText, familyMenuText, choiceSubTitleText, continueSubWindowText, quitSubWindowText;
        InfoBox subWindowRect, barSubWindowRect, textAreaRect;
        ManagerGUI managerGui;
        sf::CircleShape circle, triangle, square, hexagon, pentagon;
        sf::RectangleShape rectangle;
    public:
        screen_0(void);
        virtual int Run(sf::RenderWindow &App);
        int load();
        void initText();
        void initShape();
};
const int FONT_SIZE = 18;

const int WINDOW = 1;

const int TITLE_TEXT = 1;
const int PSEUDO_TEXT = 2;
const int SUB_TITLE_NAME_TEXT = 3;
const int SUB_TITLE_FAMILY_TEXT = 4;
const int SUB_TITLE_CHOICE_TEXT = 5;
const int CONTINUE_TEXT = 6;
const int QUIT_TEXT = 7;
}

using namespace screen0;

screen_0::screen_0(void) {
}




int screen_0::Run(sf::RenderWindow &App) {
    sf::Event Event;
    bool running = true;

    sf::String textes;
    bool typeOn = false;

    load();

    initShape();
    initText();


    // Detection area
    /*sf::FloatRect textAreaDetection(textAreaRect.getPosition().x, textAreaRect.getPosition().y, textAreaRect.getSize().x, textAreaRect.getSize().y);
    sf::FloatRect circleDetection(circle.getPosition().x, circle.getPosition().y, circle.getLocalBounds().width , circle.getLocalBounds().width);
    sf::FloatRect triangleDetection(triangle.getPosition().x, triangle.getPosition().y, triangle.getLocalBounds().width, triangle.getLocalBounds().width);
    sf::FloatRect squareDetection(square.getPosition().x, square.getPosition().y, square.getLocalBounds().width, square.getLocalBounds().width);
    sf::FloatRect rectangleDetection(rectangle.getPosition().x, rectangle.getPosition().y, rectangle.getSize().x, rectangle.getSize().y);
    sf::FloatRect hexagonDetection(hexagon.getPosition().x, hexagon.getPosition().y, hexagon.getLocalBounds().width, hexagon.getLocalBounds().width);
    sf::FloatRect pentagonDetection(pentagon.getPosition().x, pentagon.getPosition().y, pentagon.getLocalBounds().width, pentagon.getLocalBounds().width);
    sf::FloatRect continueTextDetectionDetection(continueSubWindowText.getPosition().x, continueSubWindowText.getPosition().y, continueSubWindowText.getGlobalBounds().width, continueSubWindowText.getGlobalBounds().height);
    sf::FloatRect quitTextDetectionDetection(quitSubWindowText.getPosition().x, quitSubWindowText.getPosition().y, quitSubWindowText.getGlobalBounds().width, quitSubWindowText.getGlobalBounds().height);
*/



    while (running) {
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }

            // Collision detection
            /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && textAreaDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
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

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(quitTextDetectionDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color(16, 52, 166, 255));

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(pentagonDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(16, 52, 166, 255));
            }else if(hexagonDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(16, 52, 166, 255));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(rectangleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(16, 52, 166, 255));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(squareDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(16, 52, 166, 255));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(triangleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(0, 0, 0));
                triangle.setOutlineColor(sf::Color(16, 52, 166, 255));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }else if(circleDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(16, 52, 166, 255));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));
            }

            if(typeOn){
               if (Event.type == sf::Event::TextEntered){
                   if (Event.text.unicode < 128){
                        textes += Event.text.unicode;
                        text.setString(textes);
                   }
                }
            }*/
        }





        App.clear(sf::Color(255, 255, 255, 255));
        managerGui.draw(App);
        /* App.draw(subWindowRect);
        App.draw(barSubWindowRect);
        App.draw(textAreaRect);

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
        App.draw(pentagon);*/

        //App.draw(text);
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
    /*text.setFont(font);
    text.setCharacterSize(FONT_SIZE);
    text.setColor(sf::Color::Black);
    text.setPosition(125, 190);*/

    managerGui.addText(font, FONT_SIZE, "Birth-certificate", sf::Color::White, {105.f, 105.f}, TITLE_TEXT);

    managerGui.addText(font, FONT_SIZE, "Continue", sf::Color::Black, {200.f, 470.f}, CONTINUE_TEXT);

    managerGui.addText(font, FONT_SIZE, "Quit", sf::Color::Black, {200.f, 490.f}, QUIT_TEXT);

    managerGui.addText(font, FONT_SIZE, "1. What's your name ?", sf::Color(0, 0, 0, 255), {170.f, 160.f}, SUB_TITLE_NAME_TEXT);

    managerGui.addText(font, FONT_SIZE, "2. What's your family ?", sf::Color(0, 0, 0, 255), {170.f, 270.f}, SUB_TITLE_FAMILY_TEXT);

    managerGui.addText(font, FONT_SIZE, "3. Now make a choice", sf::Color(0, 0, 0, 255), {170.f, 450.f}, SUB_TITLE_CHOICE_TEXT);
}

void screen_0::initShape() {

    managerGui.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), WINDOW);

    // Input text area
    managerGui.addShape(sf::Vector2f(250, 25), sf::Vector2f(120, 185), sf::Color(255, 255, 255, 255), 2.f, sf::Color(0, 0, 0));

    // Circle
    managerGui.addShape(25, sf::Vector2f(120, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));

    // Triangle
    managerGui.addShape(30, 3, sf::Vector2f(180, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));

    // Square
    managerGui.addShape(30, 4, sf::Vector2f(250, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));

    // Rectangle
    managerGui.addShape(sf::Vector2f(70, 40), sf::Vector2f(120, 390), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));

    // Hexagon
    managerGui.addShape(30, 6, sf::Vector2f(220, 380), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));

    // Pentagon
    managerGui.addShape(30, 5, sf::Vector2f(290, 380), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0));
}
