#include <SFML/Graphics.hpp>

class WindowCreateThing : public Window {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice;
        sf::Text createThingText;
        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;
        sf::RectangleShape taskbar, buttonMainMenu, buttonsSubMenu;
        sf::Text anythingText;
        sf::Font font;
        sf::Font f;
        sf::Text textTitle;
        sf::Sprite spriteFodler, spriteClose;
    public:
        WindowCreateThing(void);
        void init(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        int load();
        void update(sf::RenderWindow &window);
};

WindowCreateThing::WindowCreateThing(void) {

}



void WindowCreateThing::init(sf::RenderWindow &window) {

    rectTitle.setSize(sf::Vector2f(window.getSize().x*0.45, window.getSize().y*0.07));
    rectTitle.setPosition(sf::Vector2f(window.getSize().x/2-(rectTitle.getSize().x/2), window.getSize().x/4-(rectTitle.getSize().y/2)));
    rectTitle.setFillColor(sf::Color(158, 158, 158));

    rectMain.setSize(sf::Vector2f(window.getSize().x*0.45,window.getSize().y*0.45));
    rectMain.setPosition(sf::Vector2f(rectTitle.getPosition().x, rectTitle.getPosition().y+rectTitle.getSize().y));
    rectMain.setFillColor(sf::Color::White);

    load();


    starting_position = sf::Mouse::getPosition(window);



    //textTitle.setFont(font);
    textTitle.setString("newLife.txt");
    textTitle.setCharacterSize(24);
    textTitle.setColor(sf::Color::White);
    textTitle.setPosition(sf::Vector2f(rectTitle.getPosition().x+rectTitle.getSize().x*0.3, rectTitle.getPosition().y+rectTitle.getSize().y*0.1));

    ///// FOLDER ICONE
    textureFolder.setSmooth(true);
    spriteFodler.setTexture(textureFolder);
    sf::Vector2f targetSize(25.0f, 25.0f);
    spriteFodler.setScale(
        targetSize.x / spriteFodler.getLocalBounds().width,
        targetSize.y / spriteFodler.getLocalBounds().height);
    spriteFodler.setPosition(sf::Vector2f(textTitle.getPosition().x-targetSize.x, textTitle.getPosition().y));




    ///// CLOSE ICONE
    textureClose.setSmooth(true);
    spriteClose.setTexture(textureClose);
    sf::Vector2f targetSize2(window.getSize().y*0.07, window.getSize().y*0.07);
    spriteClose.setScale(
        targetSize2.x / spriteClose.getLocalBounds().width,
        targetSize2.y / spriteClose.getLocalBounds().height);
    spriteClose.setPosition(rectTitle.getPosition().x+rectTitle.getSize().x-targetSize2.x, rectTitle.getPosition().y);
}




void WindowCreateThing::draw(sf::RenderWindow &window) {
    window.draw(rectMain);
    window.draw(rectTitle);



    window.draw(textTitle);

    window.draw(spriteFodler);

    window.draw(spriteClose);
    std::cout << "etllaa" << std::endl;
}

int WindowCreateThing::load() {

    if (!textureFolder.loadFromFile("folder.png")) {
        std::cerr << "Error loading folder.png" << std::endl;
        return (-1);
    }

    if (!textureClose.loadFromFile("close.png")) {
        std::cerr << "Error loading close.png" << std::endl;
        return (-1);
    }
    return 0;
}

void WindowCreateThing::update(sf::RenderWindow &window) {

    if( sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        starting_position.x = sf::Mouse::getPosition(window).x;
        starting_position.y = sf::Mouse::getPosition(window).y;
    }

    if( sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) ){
        rectTitle.setPosition( starting_position.x/*+(rectTitle.getSize().x-starting_position.x)*/ , starting_position.y );
        rectMain.setPosition(sf::Vector2f(rectTitle.getPosition().x, rectTitle.getPosition().y+rectTitle.getSize().y));
    }
}
