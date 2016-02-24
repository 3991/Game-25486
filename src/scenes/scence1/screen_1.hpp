#include <iostream>
#include "../cScreen.hpp"
#include "creator/Creator.hpp"
#include "ManagerGui.hpp"
#include <SFML/Graphics.hpp>

namespace screen1{
    class screen_1 : public cScreen{
        private:
            sf::RectangleShape player, menuBarRect, builduingRect, infoRect;
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
            sf::RectangleShape player, menuBarRect, builduingRect, infoRect;
=======
            sf::RectangleShape rectangle, menuBarRect, builduingRect, engineerRect, infoRect;
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
            sf::Text employeesText, engineerText, directorText, createBuildingText, modifyBuildingText, createTemwork, buildingImagine, dayText, moneyText, reputationText;
            sf::Font font;
            ManagerGui managerGUI;
            Creator creator;
            int day, money;
            sf::Clock clock;
            int elapsed1;
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
            sf::Clock clock;
            int elapsed1;
=======
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
        public:
            screen_1(void);
            virtual int Run(sf::RenderWindow &App);
            int load();
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
            void initRectangleShape(sf::RectangleShape &rectangle, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);
            void initRectangleShape(sf::RectangleShape &rectangle, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &outlineColor);
            void initText(sf::Text &text, const sf::Font &font, const int &characterSize, const std::string &message, const sf::Vector2f &position, const sf::Color &color);
            void createNotAvailablePage(const int &number, const int &idPane);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
    };

    const int SPEED = 7;

    const int WINDOW_CREATE_BUILDING_ID = 1;
    const int WINDOW_CREATE_TEAMWORK_ID = 2;
    const int WINDOW_EMPLAYEES_ID = 3;
    const int WINDOW_DESTROY_BUILDING_ID = 4;
    const int WINDOW_MANAGE_TEAMWORK_ID = 5;
    const int WINDOW_BUILDING_IMAGINE_ID = 6;
    const int WINDOW_DIRECTOR_ID = 7;
    const int WINDOW_ENGINEER_ID = 8;
    const int WINDOW_MODIFY_BUILDING_ID = 9;

    const int TITLE_TEXT_ID = 1;
    const int SUB_TITLE_NAME_TEXT_ID = 2;
    const int TEXT_AREA_SHAPE_ID = 3;
    const int SUB_TITLE_WHY_TEXT_ID = 4;
    const int CHECK_MAKE_ID = 5;
    const int CHECK_SOLD_ID = 6;
    const int CHECK_BUY_ID = 7;
    const int CHECK_MAKE_TEXT_ID = 8;
    const int CHECK_SOLD_TEXT_ID = 9;
    const int CHECK_BUY_TEXT_ID = 10;
}

using namespace screen1;

screen_1::screen_1(void){
    initRectangleShape(player, sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Color::White, 3, sf::Color::Black);
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
    initRectangleShape(player, sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Color::White, 3, sf::Color::Black);
=======
    rectangle.setOutlineThickness(3);
    rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
    rectangle.setSize({50.f, 50.f});
    rectangle.setPosition({50.f, 50.f});
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
}

int screen_1::Run(sf::RenderWindow &App){
    sf::Event Event;
    bool Running = true, testMenu1 = false, click = false, ingameMode = true, startDrawning = false;
    day = 1, money = 0;
=======
<<<<<<< HEAD
    day = 1, money = 0;
    int x, y;
    elapsed1 = 0;
    load();

    sf::View view1(sf::FloatRect(0, 0, 800, 600));
    view1.setCenter(player.getPosition());

    creator.init(font, 18);


    initRectangleShape(menuBarRect, sf::Vector2f(800, 30), sf::Vector2f(0, 0), sf::Color(237, 237, 237));
    initRectangleShape(builduingRect, sf::Vector2f(250, 200), sf::Vector2f(5, 5), sf::Color(245, 245, 245, 250));
    initRectangleShape(infoRect, sf::Vector2f(170, 110), sf::Vector2f(680, 40), sf::Color(245, 245, 245, 220), 1, sf::Color(237, 237, 237));


    initText(dayText, font, 18, ">Day 1", sf::Vector2f(690, 40), sf::Color::Black);
    initText(moneyText, font, 18, ">$0", sf::Vector2f(690, 60), sf::Color::Black);
    initText(reputationText, font, 18, ">0 friend(s)", sf::Vector2f(690, 80), sf::Color::Black);


<<<<<<< HEAD

=======
=======
    day = 0, money = 0;
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
    int x, y;
    elapsed1 = 0;
    load();

    sf::View view1(sf::FloatRect(0, 0, 800, 600));
    view1.setCenter(player.getPosition());

    creator.init(font, 18);


    initRectangleShape(menuBarRect, sf::Vector2f(800, 30), sf::Vector2f(0, 0), sf::Color(237, 237, 237));
    initRectangleShape(builduingRect, sf::Vector2f(250, 200), sf::Vector2f(5, 5), sf::Color(245, 245, 245, 250));
    initRectangleShape(infoRect, sf::Vector2f(170, 110), sf::Vector2f(680, 40), sf::Color(245, 245, 245, 220), 1, sf::Color(237, 237, 237));


    initText(dayText, font, 18, ">Day 1", sf::Vector2f(690, 40), sf::Color::Black);
    initText(moneyText, font, 18, ">$0", sf::Vector2f(690, 60), sf::Color::Black);
    initText(reputationText, font, 18, ">0 friend(s)", sf::Vector2f(690, 80), sf::Color::Black);



<<<<<<< HEAD
=======
    reputationText.setFont(font);
    reputationText.setCharacterSize(18);
    reputationText.setString(">0 friend(s)");
    reputationText.setPosition({ 690.f, 80.f });
    reputationText.setColor(sf::Color::Black);
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343

    //Employes - Ingenieers - director
    // create building - destroy - modify
    //Creat teamwork - manage - building imagine
    //create complany
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
<<<<<<< HEAD
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
    initText(employeesText, font, 18, "Anything", sf::Vector2f(10, 5), sf::Color::Black);
    initText(createBuildingText, font, 18, ">>Create a thing", sf::Vector2f(10, 30), sf::Color(96,96,96));
    initText(createTemwork, font, 18, ">>Team work", sf::Vector2f(10, 60), sf::Color(96,96,96));
    initText(buildingImagine, font, 18, ">>Money", sf::Vector2f(10, 90), sf::Color(96,96,96));
    initText(directorText, font, 18, ">>Big company", sf::Vector2f(10, 120), sf::Color(96,96,96));
    initText(engineerText, font, 18, ">>World", sf::Vector2f(10, 150), sf::Color(96,96,96));
    initText(modifyBuildingText, font, 18, ">>Go away", sf::Vector2f(10, 180), sf::Color(96,96,96));


<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
=======
    employeesText.setFont(font);
    employeesText.setCharacterSize(18);
    employeesText.setString("Anything");
    employeesText.setPosition({ 10.f, 5.f });
    employeesText.setColor(sf::Color::Black);

    createBuildingText.setFont(font);
    createBuildingText.setCharacterSize(18);
    createBuildingText.setString(">>Create a thing");
    createBuildingText.setPosition({ 10.f, 30.f });
    createBuildingText.setColor(sf::Color(96,96,96));

    createTemwork.setFont(font);
    createTemwork.setCharacterSize(18);
    createTemwork.setString(">>Team work");
    createTemwork.setPosition({ 10.f, 60.f });
    createTemwork.setColor(sf::Color(96,96,96));

    buildingImagine.setFont(font);
    buildingImagine.setCharacterSize(18);
    buildingImagine.setString(">>Money");
    buildingImagine.setPosition({ 10.f, 90.f });
    buildingImagine.setColor(sf::Color(96,96,96));

    directorText.setFont(font);
    directorText.setCharacterSize(18);
    directorText.setString(">>Big company");
    directorText.setPosition({ 10.f, 120.f });
    directorText.setColor(sf::Color(96,96,96));

    engineerText.setFont(font);
    engineerText.setCharacterSize(18);
    engineerText.setString(">>World");
    engineerText.setPosition({ 10.f, 150.f });
    engineerText.setColor(sf::Color(96,96,96));

    modifyBuildingText.setFont(font);
    modifyBuildingText.setCharacterSize(18);
    modifyBuildingText.setString(">>Go away");
    modifyBuildingText.setPosition({ 10.f, 180.f });
    modifyBuildingText.setColor(sf::Color(96,96,96));
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343

    sf::FloatRect employeesTextDetection(employeesText.getPosition().x, employeesText.getPosition().y, employeesText.getGlobalBounds().width, employeesText.getGlobalBounds().height);
    sf::FloatRect createBuilduigTextDetection(createBuildingText.getPosition().x, createBuildingText.getPosition().y, createBuildingText.getGlobalBounds().width, createBuildingText.getGlobalBounds().height);
    sf::FloatRect createTemworkDetection(createTemwork.getPosition().x, createTemwork.getPosition().y, createTemwork.getGlobalBounds().width, createTemwork.getGlobalBounds().height);
    sf::FloatRect buildingImagineDetection(buildingImagine.getPosition().x, buildingImagine.getPosition().y, buildingImagine.getGlobalBounds().width, buildingImagine.getGlobalBounds().height);
    sf::FloatRect directorTextDetection(directorText.getPosition().x, directorText.getPosition().y, directorText.getGlobalBounds().width, directorText.getGlobalBounds().height);
    sf::FloatRect engineerTextDetection(engineerText.getPosition().x, engineerText.getPosition().y, engineerText.getGlobalBounds().width, engineerText.getGlobalBounds().height);
    sf::FloatRect modifyBuildingTextDetection(modifyBuildingText.getPosition().x, modifyBuildingText.getPosition().y, modifyBuildingText.getGlobalBounds().width, modifyBuildingText.getGlobalBounds().height);

    sf::FloatRect builduigRectDetection(builduingRect.getPosition().x, builduingRect.getPosition().y, builduingRect.getGlobalBounds().width, builduingRect.getGlobalBounds().height);


    //int xco = 0, yco = 0;
<<<<<<< HEAD

=======
=======

    sf::FloatRect builduigRectDetection(builduingRect.getPosition().x, builduingRect.getPosition().y, builduingRect.getGlobalBounds().width, builduingRect.getGlobalBounds().height);


<<<<<<< HEAD
    //int xco = 0, yco = 0;

=======
int xco = 0, yco = 0;
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343

    while (Running){
        while (App.pollEvent(Event)){
            if (Event.type == sf::Event::Closed){
                return (-1);
            }
        }

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
<<<<<<< HEAD
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
        // --------- TIME ---------
        if(elapsed1 != (int)clock.getElapsedTime().asSeconds()){
            if(elapsed1 == 24){
                clock.restart();
                elapsed1=0;
                day++;
            }
            std::cout << "[day "<< day << "] " << elapsed1 << " heures" << std::endl;
        }
        elapsed1 = (int)clock.getElapsedTime().asSeconds();

        // --------- TIME END ---------


        /*if((xco != sf::Mouse::getPosition(App).x) && (yco != sf::Mouse::getPosition(App).y)){
<<<<<<< HEAD
=======
            xco = sf::Mouse::getPosition(App).x;
            yco = sf::Mouse::getPosition(App).y;
        }*/

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-SPEED, 0);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(+SPEED,0);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0,-SPEED);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0,+SPEED);
            view1.setCenter(player.getPosition());
            //creator.linesUP();
<<<<<<< HEAD

=======
=======
        if((xco != sf::Mouse::getPosition(App).x) && (yco != sf::Mouse::getPosition(App).y)){
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
            xco = sf::Mouse::getPosition(App).x;
            yco = sf::Mouse::getPosition(App).y;
        }*/

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-SPEED, 0);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(+SPEED,0);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0,-SPEED);
            view1.setCenter(player.getPosition());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
<<<<<<< HEAD
            player.move(0,+SPEED);
            view1.setCenter(player.getPosition());
            //creator.linesUP();

=======
            rectangle.move(0,+SPEED);
            day++;
            creator.linesUP();
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
        }


        if(employeesTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            testMenu1 = true;
        }else{
            if(builduigRectDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && testMenu1){
                testMenu1 = true;
            }else{
                testMenu1 = false;
            }
        }


        createBuildingText.setColor(sf::Color(96,96,96));
        createTemwork.setColor(sf::Color(96,96,96));
        employeesText.setColor(sf::Color(96,96,96));
        buildingImagine.setColor(sf::Color(96,96,96));
        engineerText.setColor(sf::Color(96,96,96));
        modifyBuildingText.setColor(sf::Color(96,96,96));
        directorText.setColor(sf::Color(96,96,96));

        if(createBuilduigTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            createBuildingText.setColor(sf::Color::Black);
        }else if(createTemworkDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            createTemwork.setColor(sf::Color::Black);
        }else if(employeesTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            employeesText.setColor(sf::Color::Black);
        }else if(buildingImagineDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            buildingImagine.setColor(sf::Color::Black);
        }else if(engineerTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            engineerText.setColor(sf::Color::Black);
        }else if(modifyBuildingTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            modifyBuildingText.setColor(sf::Color::Black);
        }else if(directorTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)) {
            directorText.setColor(sf::Color::Black);
        }


        if(ingameMode){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && createBuilduigTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click) {
                click = true;
<<<<<<< HEAD

                testMenu1 = false;

=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
                testMenu1 = false;
=======
                /*managerGUI.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), WINDOW_CREATE_BUILDING);
                managerGUI.addText(font, FONT_SIZE, "Create a thing", sf::Color::White, {105.f, 105.f}, TITLE_TEXT, WINDOW_CREATE_BUILDING, false);
                managerGUI.addText(font, FONT_SIZE, "1. A person, a money, a building?", sf::Color(0, 0, 0, 255), {170.f, 160.f}, SUB_TITLE_NAME_TEXT, WINDOW_CREATE_BUILDING, false);
                managerGUI.addShape(sf::Vector2f(250, 25), sf::Vector2f(120, 185), sf::Color(255, 255, 255, 255), 2.f, sf::Color(0, 0, 0), TEXT_AREA_SHAPE, WINDOW_CREATE_BUILDING, true);
                managerGUI.addText(font, FONT_SIZE, "2. Why ?", sf::Color(0, 0, 0, 255), {170.f, 220.f}, SUB_TITLE_WHY_TEXT, WINDOW_CREATE_BUILDING, false);
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2

                testMenu1 = false;

<<<<<<< HEAD
=======
                managerGUI.addShape(sf::Vector2f(10, 10), sf::Vector2f(120, 290), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), CHECK_BUY, WINDOW_CREATE_BUILDING, true);
                managerGUI.addText(font, FONT_SIZE, "Buy", sf::Color(0, 0, 0, 255), {140.f, 280.f}, CHECK_BUY_TEXT, WINDOW_CREATE_BUILDING, false);*/
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
                ingameMode = false;
                creator.setCreateMode(true);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && createTemworkDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
<<<<<<< HEAD

=======
<<<<<<< HEAD

                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_CREATE_TEAMWORK_ID);
=======
<<<<<<< HEAD
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_CREATE_TEAMWORK_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && employeesTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_EMPLAYEES_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && buildingImagineDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_BUILDING_IMAGINE_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && directorTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_DIRECTOR_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && engineerTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_ENGINEER_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && modifyBuildingTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_MODIFY_BUILDING_ID);
<<<<<<< HEAD
=======
=======
                managerGUI.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), WINDOW_CREATE_TEAMWORK_ID);
                managerGUI.addText(font, FONT_SIZE, "Info1", sf::Color::Red, {105.f, 105.f}, TITLE_TEXT, WINDOW_CREATE_TEAMWORK_ID, false);
                managerGUI.addText(font, FONT_SIZE, "Not available", sf::Color::Red, {170.f, 160.f}, SUB_TITLE_NAME_TEXT, WINDOW_CREATE_TEAMWORK_ID, false);
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && employeesTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_EMPLAYEES_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && buildingImagineDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_BUILDING_IMAGINE_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && directorTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_DIRECTOR_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && engineerTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_ENGINEER_ID);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && modifyBuildingTextDetection.contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !click){
                click = true;
<<<<<<< HEAD
                testMenu1 = false;
                createNotAvailablePage(SUB_TITLE_NAME_TEXT, WINDOW_MODIFY_BUILDING_ID);
=======
                managerGUI.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), WINDOW_MODIFY_BUILDING_ID);
                managerGUI.addText(font, FONT_SIZE, "Info", sf::Color::Red, {105.f, 105.f}, TITLE_TEXT, WINDOW_MODIFY_BUILDING_ID, false);
                managerGUI.addText(font, FONT_SIZE, "Not available", sf::Color::Red, {170.f, 160.f}, SUB_TITLE_NAME_TEXT, WINDOW_MODIFY_BUILDING_ID, false);
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
            }
        }else if(creator.getCreateMode()){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && creator.getDrawningArea().contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && !startDrawning && !click){
                x = sf::Mouse::getPosition(App).x;
                y = sf::Mouse::getPosition(App).y;
                creator.createCurrentLine(x, y, x, y);

                startDrawning = true;
                click = true;
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && creator.getDrawningArea().contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y) && startDrawning && !click){
                creator.addLineList();
                click = true;

                creator.createCurrentLine(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y, sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y);
            }else if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && creator.getDrawningArea().contains(sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y)){
                startDrawning = false;
            }
        }

        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            click = false;
        }

        creator.updateSelection(App);

<<<<<<< HEAD
=======
=======
<<<<<<< HEAD

=======
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
        if(!creator.getCreateMode()){
            ingameMode = true;
        }

        // ------------------------------------------ Display ------------------------------------------

        App.clear(sf::Color(255, 255, 255, 255));




=======
<<<<<<< HEAD

        if(ingameMode){
            App.setView(view1);
            App.draw(player);
            managerGUI.drawLines(App, creator.getLines());

            App.setView(App.getDefaultView());
<<<<<<< HEAD
=======
=======
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
        if(ingameMode){
            App.setView(view1);
            App.draw(player);
            managerGUI.drawLines(App, creator.getLines());

            App.setView(App.getDefaultView());
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343

            managerGUI.draw(App);

            if(testMenu1 && !click){
                App.draw(builduingRect);
                App.draw(createBuildingText);
                App.draw(modifyBuildingText);
                App.draw(createTemwork);
                App.draw(buildingImagine);
                App.draw(directorText);
                App.draw(engineerText);
            }

            App.draw(menuBarRect);

            App.draw(employeesText);

            App.draw(infoRect);
            App.draw(dayText);
            App.draw(moneyText);
            App.draw(reputationText);

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
            managerGUI.drawLines(App, creator.getLines());
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
        }else if(creator.getCreateMode()){
            creator.draw(App);

            if(startDrawning){
                creator.drawCurrentLine(App, sf::Mouse::getPosition(App).x, sf::Mouse::getPosition(App).y);
            }
            creator.drawLines(App);

        }

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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343

void screen_1::initRectangleShape(sf::RectangleShape &rectangle, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color) {
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
}

void screen_1::initRectangleShape(sf::RectangleShape &rectangle, const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &outlineColor) {
    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(color);
    rectangle.setOutlineThickness(thickness);
    rectangle.setOutlineColor(outlineColor);
}

void screen_1::initText(sf::Text &text, const sf::Font &font, const int &characterSize, const std::string &message, const sf::Vector2f &position, const sf::Color &color) {
    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setString(message);
    text.setPosition(position);
    text.setColor(color);
}

void screen_1::createNotAvailablePage(const int &number, const int &idPane) {
    managerGUI.addSubwindow(sf::Vector2f(300, 450), sf::Vector2f(100, 100), sf::Color(237, 237, 237), 3.f, sf::Color(0, 0, 0), idPane);
    managerGUI.addText(font, FONT_SIZE, "Info", sf::Color::Red, {105.f, 105.f}, TITLE_TEXT, idPane, false);
    managerGUI.addText(font, FONT_SIZE, "Not available", sf::Color::Red, {170.f, 160.f}, number, idPane, false);
}
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

=======
>>>>>>> da628c3eb9e8d94f0b1709eeb705b6a9daa50b0f
>>>>>>> 16f2d19701414918327faad9e778542f8b77fca2
>>>>>>> a5206a9dc68e2d0a9976ddbfa41db301023fb343
