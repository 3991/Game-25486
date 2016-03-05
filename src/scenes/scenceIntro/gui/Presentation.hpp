#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <tchar.h>

class Presentation {
    private:
        sf::RectangleShape rectTitle, rectMain, rectChoice, rectTest;

        sf::Text createThingText;
        sf::Texture textureFolder, textureClose;
        sf::Vector2i starting_position;
        sf::Font font;
        // INTRO
        char str[80];
    public:
        Presentation(void);

        int load() ;

        void update(sf::RenderWindow &window);

        //INTRO
        void initIntro(sf::RenderWindow &window);
        void drawIntro(sf::RenderWindow &window);
};

Presentation::Presentation(void) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading arial.ttf" << std::endl;
    }

}


void Presentation::initIntro(sf::RenderWindow &window){


    load();


}

void Presentation::drawIntro(sf::RenderWindow &window){
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
}


int Presentation::load() {



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
