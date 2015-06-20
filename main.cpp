#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/scenes/screens.hpp"

int main(int argc, char** argv)
{
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Game 25486", sf::Style::Default, settings);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(true);



    //Screens preparations
    screen_0 s0;
    Screens.push_back(&s0);
    screen_1 s1;
    Screens.push_back(&s1);

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}

