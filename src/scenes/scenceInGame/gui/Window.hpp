#include <SFML/Graphics.hpp>

class Window {
    private:
       sf::RectangleShape rectTitle, rectMain, rectChoice, rectTest;

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
        void initMainMenu(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        int load();
        void update(sf::RenderWindow &window);
};

Window::Window(void) {

}

void Window::initMainMenu(sf::RenderWindow &window) {

    rectTitle.setSize(sf::Vector2f(window.getSize().x*0.45, window.getSize().y*0.07));
    rectTitle.setPosition(sf::Vector2f(window.getSize().x/2-(rectTitle.getSize().x/2), window.getSize().x/4-(rectTitle.getSize().y/2)));
    rectTitle.setFillColor(sf::Color(158, 158, 158));

    rectMain.setSize(sf::Vector2f(window.getSize().x*0.45,window.getSize().y*0.45));
    rectMain.setPosition(sf::Vector2f(rectTitle.getPosition().x, rectTitle.getPosition().y+rectTitle.getSize().y));
    rectMain.setFillColor(sf::Color::White);

    load();


    starting_position = sf::Mouse::getPosition( window );


}




/*void Window::initIntro(sf::RenderWindow &window){


    load();


}

void Window::drawIntro(sf::RenderWindow &window){
     sf::Font ibm;
    sf::Font font;
    if (!ibm.loadFromFile("ibm.ttf")) {
        std::cerr << "Error loading ibm.ttf" << std::endl;
        //return (-1);
    }
    sf::Text textTitleIntro;
    textTitleIntro.setFont(ibm);
    textTitleIntro.setString("HELLO");
    textTitleIntro.setCharacterSize(100);
    textTitleIntro.setColor(sf::Color::White);
    textTitleIntro.setOrigin(textTitleIntro.getLocalBounds().left+textTitleIntro.getLocalBounds().width/2.0f, textTitleIntro.getLocalBounds().top+textTitleIntro.getLocalBounds().height/2.0f);
    textTitleIntro.setPosition(window.getSize().x/2, textTitleIntro.getLocalBounds().height/1.5f);


   window.draw(textTitleIntro);


    TCHAR nameBuf[MAX_COMPUTERNAME_LENGTH + 2];
    DWORD nameBufSize;

    nameBufSize = sizeof nameBuf - 1;
    if (GetUserName(nameBuf, &nameBufSize) == TRUE) {
    //_tprintf(_T("Your computer name is %s\n"), nameBuf);
    }
    //std::cout << nameBuf << std::endl;
    strcpy (str,"HELLO (C) ");
    strcat (str,nameBuf);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading arial.ttf" << std::endl;
        //return (-1);
    }
    sf::Text textSubTitleIntro;
    textSubTitleIntro.setFont(font);
    textSubTitleIntro.setString(str);
    textSubTitleIntro.setCharacterSize(25);
    textSubTitleIntro.setColor(sf::Color::White);
    textSubTitleIntro.setPosition(20, window.getSize().y/2);
    window.draw(textSubTitleIntro);

    sf::Text textContinueIntro;
    textContinueIntro.setFont(font);
    textContinueIntro.setString("Space to continue or Esc to cancel");
    textContinueIntro.setCharacterSize(25);
    textContinueIntro.setColor(sf::Color::White);
    textContinueIntro.setPosition(20, window.getSize().y/3);
    window.draw(textContinueIntro);
}*/


void Window::draw(sf::RenderWindow &window) {
    window.draw(rectMain);
    window.draw(rectTitle);




    sf::Text textTitle;
    //textTitle.setFont(font);
    textTitle.setString("newLife.txt");
    textTitle.setCharacterSize(24);
    textTitle.setColor(sf::Color::White);
    textTitle.setPosition(sf::Vector2f(rectTitle.getPosition().x+rectTitle.getSize().x*0.3, rectTitle.getPosition().y+rectTitle.getSize().y*0.1));


    // sf::Texture textureFolder, textureClose;
        sf::Sprite spriteFodler, spriteClose;

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




    window.draw(textTitle);

    window.draw(spriteFodler);


    window.draw(spriteClose);
}

int Window::load() {

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
