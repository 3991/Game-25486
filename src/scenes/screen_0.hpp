#include <iostream>
#include "cScreen.hpp"
#include "../gui/Pane.hpp"
#include "../gui/ManagerGUI.hpp"
#include <SFML/Graphics.hpp>

namespace screen0
{
class screen_0 : public cScreen {
    private:
        sf::Font font;
        sf::Text text, tileSubWindowText, nameMenuText, familyMenuText, choiceSubTitleText, continueSubWindowText, quitSubWindowText;
        Pane subWindowRect, barSubWindowRect, ;
        ManagerGUI managerGui;
        sf::CircleShape circle, triangle, square, hexagon, pentagon;
        sf::RectangleShape rectangle, textAreaRect;
        sf::FloatRect textAreaDetection, continueTextDetectionDetection, quitTextDetectionDetection, circleDetection, triangleDetection, squareDetection, hexagonDetection, pentagonDetection, rectangleDetection;
    public:
        screen_0(void);
        virtual int Run(sf::RenderWindow &App);
        int load();
        void initText();
        void initShape();
        sf::FloatRect createDetectionArea(sf::FloatRect rect, float left, float top, float width, float height) const;
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

const int CIRCLE_SHAPE = 1;
const int TRIANGLE_SHAPE = 2;
const int SQUARE_SHAPE = 3;
const int HEXAGON_SHAPE = 4;
const int PENTAGON_SHAPE = 5;
const int RECTANGLE_SHAPE = 6;
const int TEXT_AREA_SHAPE = 7;
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
    std::list<Content> t;
    t = managerGui.getTexts(WINDOW);

    for(std::list<Content>::iterator inte = t.begin(); inte != t.end(); inte++){
        if(inte->getNumber() == CONTINUE_TEXT){
            continueTextDetectionDetection = createDetectionArea(continueTextDetectionDetection, inte->sf::Text::getPosition().x, inte->sf::Text::getPosition().y, inte->sf::Text::getGlobalBounds().width, inte->sf::Text::getGlobalBounds().height);
        }else if(inte->getNumber() == QUIT_TEXT){

           quitTextDetectionDetection = createDetectionArea(quitTextDetectionDetection, inte->sf::Text::getPosition().x, inte->sf::Text::getPosition().y, inte->sf::Text::getGlobalBounds().width, inte->sf::Text::getGlobalBounds().height);
        }
    }

    std::list<Content> c;
    c = managerGui.getCircles(WINDOW);

    for(std::list<Content>::iterator inte = c.begin(); inte != c.end(); inte++){
        if(inte->getNumber() == CIRCLE_SHAPE){
            circle = *inte;
            circleDetection = createDetectionArea(circleDetection, inte->sf::CircleShape::getPosition().x, inte->sf::CircleShape::getPosition().y, inte->sf::CircleShape::getLocalBounds().width , inte->sf::CircleShape::getLocalBounds().width);
        }else if(inte->getNumber() == TRIANGLE_SHAPE){
            triangleDetection = createDetectionArea(triangleDetection, inte->sf::CircleShape::getPosition().x, inte->sf::CircleShape::getPosition().y, inte->sf::CircleShape::getLocalBounds().width, inte->sf::CircleShape::getLocalBounds().width);
        }else if(inte->getNumber() == SQUARE_SHAPE){
            squareDetection = createDetectionArea(squareDetection, inte->sf::CircleShape::getPosition().x, inte->sf::CircleShape::getPosition().y, inte->sf::CircleShape::getLocalBounds().width, inte->sf::CircleShape::getLocalBounds().width);
        }else if(inte->getNumber() == HEXAGON_SHAPE){
            hexagonDetection = createDetectionArea(hexagonDetection, inte->sf::CircleShape::getPosition().x, inte->sf::CircleShape::getPosition().y, inte->sf::CircleShape::getLocalBounds().width, inte->sf::CircleShape::getLocalBounds().width);
        }else if(inte->getNumber() == PENTAGON_SHAPE){
            pentagonDetection = createDetectionArea(pentagonDetection, inte->sf::CircleShape::getPosition().x, inte->sf::CircleShape::getPosition().y, inte->sf::CircleShape::getLocalBounds().width, inte->sf::CircleShape::getLocalBounds().width);
        }
    }

    std::list<Content> r;
    r = managerGui.getCircles(WINDOW);

    for(std::list<Content>::iterator inte = r.begin(); inte != r.end(); inte++){
        if(inte->getNumber() == TEXT_AREA_SHAPE){
            textAreaDetection = createDetectionArea(textAreaDetection, inte->sf::RectangleShape::getPosition().x, inte->sf::RectangleShape::getPosition().y, inte->sf::RectangleShape::getSize().x, inte->sf::RectangleShape::getSize().y);
        }else if(inte->getNumber() == RECTANGLE_SHAPE){
            rectangleDetection = createDetectionArea(rectangleDetection, inte->sf::RectangleShape::getPosition().x, inte->sf::RectangleShape::getPosition().y, inte->sf::RectangleShape::getSize().x, inte->sf::RectangleShape::getSize().y);
        }
    }



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
                /*continueSubWindowText.setColor(sf::Color::Black);
                quitSubWindowText.setColor(sf::Color::Black);

                circle.setOutlineColor(sf::Color(16, 52, 166, 255));
                triangle.setOutlineColor(sf::Color(0, 0, 0));
                square.setOutlineColor(sf::Color(0, 0, 0));
                rectangle.setOutlineColor(sf::Color(0, 0, 0));
                hexagon.setOutlineColor(sf::Color(0, 0, 0));
                pentagon.setOutlineColor(sf::Color(0, 0, 0));*/
                managerGui.resetFamilysColors(WINDOW, sf::Color::Green);
                managerGui.setColor(WINDOW, CIRCLE_SHAPE, sf::Color::Blue);
            }

            if(typeOn){
               if (Event.type == sf::Event::TextEntered){
                   if (Event.text.unicode < 128){
                        textes += Event.text.unicode;
                        text.setString(textes);
                   }
                }
            }
        }





        App.clear(sf::Color(255, 255, 255, 255));
        managerGui.draw(App);
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

sf::FloatRect screen_0::createDetectionArea(sf::FloatRect rect, float left, float top, float width, float height) const{
    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return rect;
}

void screen_0::initText() {
    /*text.setFont(font);
    text.setCharacterSize(FONT_SIZE);
    text.setColor(sf::Color::Black);
    text.setPosition(125, 190);*/

    managerGui.addText(font, FONT_SIZE, "Birth-certificate", sf::Color::White, {105.f, 105.f}, TITLE_TEXT, WINDOW, false);

    managerGui.addText(font, FONT_SIZE, "Continue", sf::Color::Black, {200.f, 470.f}, CONTINUE_TEXT, WINDOW, true);

    managerGui.addText(font, FONT_SIZE, "Quit", sf::Color::Black, {200.f, 490.f}, QUIT_TEXT, WINDOW, true);

    managerGui.addText(font, FONT_SIZE, "1. What's your name ?", sf::Color(0, 0, 0, 255), {170.f, 160.f}, SUB_TITLE_NAME_TEXT, WINDOW, false);

    managerGui.addText(font, FONT_SIZE, "2. What's your family ?", sf::Color(0, 0, 0, 255), {170.f, 270.f}, SUB_TITLE_FAMILY_TEXT, WINDOW, false);

    managerGui.addText(font, FONT_SIZE, "3. Now make a choice", sf::Color(0, 0, 0, 255), {170.f, 450.f}, SUB_TITLE_CHOICE_TEXT, WINDOW, false);
}

void screen_0::initShape() {

    managerGui.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), WINDOW);

    // Input text area
    managerGui.addShape(sf::Vector2f(250, 25), sf::Vector2f(120, 185), sf::Color(255, 255, 255, 255), 2.f, sf::Color(0, 0, 0), TEXT_AREA_SHAPE, WINDOW, true);

    // Circle
    managerGui.addShape(25, sf::Vector2f(120, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), CIRCLE_SHAPE, WINDOW, true);

    // Triangle
    managerGui.addShape(30, 3, sf::Vector2f(180, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), TRIANGLE_SHAPE, WINDOW, true);

    // Square
    managerGui.addShape(30, 4, sf::Vector2f(250, 300), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), SQUARE_SHAPE, WINDOW, true);

    // Rectangle
    managerGui.addShape(sf::Vector2f(70, 40), sf::Vector2f(120, 390), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), RECTANGLE_SHAPE, WINDOW, true);

    // Hexagon
    managerGui.addShape(30, 6, sf::Vector2f(220, 380), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), HEXAGON_SHAPE, WINDOW, true);

    // Pentagon
    managerGui.addShape(30, 5, sf::Vector2f(290, 380), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), PENTAGON_SHAPE, WINDOW, true);
}
