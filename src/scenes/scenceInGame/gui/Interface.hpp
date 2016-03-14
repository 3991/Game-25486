#include <SFML/Graphics.hpp>
#include "./Window.hpp"

class Interface {
    private:
        sf::Text createThingText, mainMenuText;
        sf::RectangleShape taskbar, buttonMainMenu, buttonsSubMenu, buttonCreateThing;
        sf::Font font;
        bool buttonMainMenuClicked, createThingOver;
        sf::Font f;
        std::vector<Window*> windows;
        Window w;
    public:
        Interface(void);
        void initInterface(sf::RenderWindow &window);
        void drawInterface(sf::RenderWindow &window);
        void updateInterface(sf::RenderWindow &window);
};

Interface::Interface(void) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading arial.ttf" << std::endl;
    }
    buttonMainMenuClicked = false;
    createThingOver = false;
}

void Interface::initInterface(sf::RenderWindow &window){

    //w.init(window);
    windows.push_back(&w);

    taskbar.setSize(sf::Vector2f(window.getSize().x, window.getSize().y*0.05));
    taskbar.setPosition(0, window.getSize().y-(window.getSize().y*0.05));
    //taskbar.setFillColor(sf::Color(176,196,222));
    taskbar.setFillColor(sf::Color::White);
    taskbar.setOutlineColor(sf::Color::Black);
    taskbar.setOutlineThickness(1.f);

    mainMenuText.setCharacterSize(18);
    mainMenuText.setString("Anything");
    mainMenuText.setFont(font);
    mainMenuText.setColor(sf::Color::Black);
    mainMenuText.setPosition(taskbar.getPosition().x+taskbar.getSize().x*0.02, taskbar.getPosition().y+taskbar.getSize().y*0.2);



    //buttonMainMenu.setSize(sf::Vector2f(taskbar.getSize().x*0.07, taskbar.getSize().y*0.6));
    buttonMainMenu.setSize(sf::Vector2f(mainMenuText.getGlobalBounds().width+10, taskbar.getSize().y));
    //buttonMainMenu.setPosition(taskbar.getPosition().x+taskbar.getSize().x*0.02, taskbar.getPosition().y+taskbar.getSize().y*0.2);
    buttonMainMenu.setPosition(mainMenuText.getPosition().x-5, taskbar.getPosition().y);
    buttonMainMenu.setFillColor(sf::Color::White);



    buttonsSubMenu.setSize(sf::Vector2f(window.getSize().x*0.3, window.getSize().y*0.5));
    buttonsSubMenu.setPosition(buttonMainMenu.getPosition().x, buttonMainMenu.getPosition().y-buttonsSubMenu.getSize().y);
    //buttonsSubMenu.setOrigin(sf::Vector2f(buttonsSubMenu.getPosition().x, buttonsSubMenu.getPosition().y+buttonsSubMenu.getSize().y));
    buttonsSubMenu.setFillColor(sf::Color::White);
    buttonsSubMenu.setOutlineColor(sf::Color::Black);
    buttonsSubMenu.setOutlineThickness(1.f);

    createThingText.setFont(font);
    createThingText.setString("Create a thing");
    createThingText.setCharacterSize(18);
    createThingText.setColor(sf::Color::Black);
    createThingText.setPosition(buttonsSubMenu.getPosition().x, buttonsSubMenu.getPosition().y);

    buttonCreateThing.setSize(sf::Vector2f(buttonsSubMenu.getSize().x, createThingText.getGlobalBounds().height+5));
    buttonCreateThing.setPosition(buttonsSubMenu.getPosition().x, buttonsSubMenu.getPosition().y);
    buttonCreateThing.setFillColor(sf::Color::White);
}

void Interface::drawInterface(sf::RenderWindow &window) {
    window.draw(taskbar);
    window.draw(buttonMainMenu);
    if(buttonMainMenuClicked){
        window.draw(buttonsSubMenu);
        if(createThingOver){
            window.draw(buttonCreateThing);
        }
        window.draw(createThingText);
    }
    window.draw(mainMenuText);


    for(unsigned int a = 0;a<windows.size(); a++){
        windows[0]->draw(window);
    }
}


void Interface::updateInterface(sf::RenderWindow &window){
    sf::FloatRect buttonMainMenuRect(buttonMainMenu.getPosition().x, buttonMainMenu.getPosition().y, buttonMainMenu.getGlobalBounds().width, buttonMainMenu.getGlobalBounds().height);
    sf::FloatRect buttonsSubMenuRect(buttonsSubMenu.getPosition().x, buttonsSubMenu.getPosition().y, buttonsSubMenu.getGlobalBounds().width, buttonsSubMenu.getGlobalBounds().height);
    if(buttonMainMenuRect.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        buttonMainMenu.setFillColor(sf::Color::Black);
        mainMenuText.setColor(sf::Color::White);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            buttonMainMenuClicked = true;
        }
    }else if(buttonsSubMenuRect.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && buttonMainMenuClicked){

    }else{
        buttonMainMenu.setFillColor(sf::Color::White);
        mainMenuText.setColor(sf::Color::Black);
        buttonMainMenuClicked = false;
    }

    sf::FloatRect createThingRect(createThingText.getPosition().x, createThingText.getPosition().y, createThingText.getGlobalBounds().width, createThingText.getGlobalBounds().height);
    if(createThingRect.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && buttonMainMenuClicked) {
        createThingText.setColor(sf::Color::White);
        buttonCreateThing.setFillColor(sf::Color::Black);
        createThingOver = true;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            std::cout << "test" << std::endl;
        }
    }else{

    }
}
