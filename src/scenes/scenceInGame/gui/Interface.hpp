#include <SFML/Graphics.hpp>

class Interface {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice, rectTest;

        sf::Text createThingText;
        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;

        // INTRO
        char str[80];

        // IN GAME
        sf::RectangleShape taskbar, buttonMainMenu, buttonsSubMenu;
        sf::Text anythingText;
        sf::Font font;
       // sf::Text creaThingText;
        sf::Font f;
    public:
        Interface(void);
        void draw(sf::RenderWindow &window);
        void initMainMenu(sf::RenderWindow &window);

        int load() ;

        void update(sf::RenderWindow &window);

        //INTRO
        void initIntro(sf::RenderWindow &window);
        void drawIntro(sf::RenderWindow &window);

        // IN GAME
        void initInterface(sf::RenderWindow &window);
        void drawInterface(sf::RenderWindow &window);
};

Interface::Interface(void) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading arial.ttf" << std::endl;
    }

}

void Interface::initInterface(sf::RenderWindow &window){
    taskbar.setSize(sf::Vector2f(window.getSize().x, window.getSize().y*0.05));
    taskbar.setPosition(0, window.getSize().y-(window.getSize().y*0.05));
    //taskbar.setFillColor(sf::Color(176,196,222));
    taskbar.setFillColor(sf::Color::White);
    taskbar.setOutlineColor(sf::Color::Black);
    taskbar.setOutlineThickness(1.f);

    anythingText.setCharacterSize(18);
    anythingText.setString("Anything");
    anythingText.setFont(font);


    anythingText.setColor(sf::Color::Black);
    anythingText.setPosition(taskbar.getPosition().x+taskbar.getSize().x*0.02, taskbar.getPosition().y+taskbar.getSize().y*0.2);



    //buttonMainMenu.setSize(sf::Vector2f(taskbar.getSize().x*0.07, taskbar.getSize().y*0.6));
    buttonMainMenu.setSize(sf::Vector2f(anythingText.getGlobalBounds().width+10, taskbar.getSize().y));
    //buttonMainMenu.setPosition(taskbar.getPosition().x+taskbar.getSize().x*0.02, taskbar.getPosition().y+taskbar.getSize().y*0.2);
    buttonMainMenu.setPosition(anythingText.getPosition().x-5, taskbar.getPosition().y);
    buttonMainMenu.setFillColor(sf::Color::White);
    //buttonMainMenu.setOutlineColor(sf::Color::Black);
    //buttonMainMenu.setOutlineThickness(5.f);



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
}

void Interface::drawInterface(sf::RenderWindow &window) {


    window.draw(taskbar);
    window.draw(buttonMainMenu);
    window.draw(buttonsSubMenu);
    window.draw(anythingText);
    window.draw(createThingText);
}


