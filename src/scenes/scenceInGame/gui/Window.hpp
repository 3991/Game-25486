#include <SFML/Graphics.hpp>

class Window {
    private:
       sf::RectangleShape rectTitle, rectMain, rectChoice;

        sf::Text createThingText;
        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;

        // IN GAME
        sf::RectangleShape taskbar, buttonMainMenu, buttonsSubMenu;
        sf::Text anythingText;
        sf::Font font;
       // sf::Text creaThingText;
        sf::Font f;
    public:
        Window(void);
        void init(sf::RenderWindow &window);
        virtual void draw(sf::RenderWindow &window);
        virtual void update(sf::RenderWindow &window);
};

Window::Window(void) {
}

void Window::init(sf::RenderWindow &window) {
}

void Window::draw(sf::RenderWindow &window) {

}



void Window::update(sf::RenderWindow &window) {

    if( sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        starting_position.x = sf::Mouse::getPosition(window).x;
        starting_position.y = sf::Mouse::getPosition(window).y;
    }

    if( sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
        rectTitle.setPosition( starting_position.x/*+(rectTitle.getSize().x-starting_position.x)*/ , starting_position.y );
        rectMain.setPosition(sf::Vector2f(rectTitle.getPosition().x, rectTitle.getPosition().y+rectTitle.getSize().y));
    }
}
