#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/scenes/screens.hpp"
#include <stdio.h>

#include <stdlib.h>


int main(int argc, char** argv){
    std::vector<cScreen*> Screens;
    int screen = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Game 25486", !sf::Style::Resize | sf::Style::Close, settings);
    App.setFramerateLimit(60);
    App.setMouseCursorVisible(true);

    screen_0 s0;
    Screens.push_back(&s0);
    screen_1 s1;
    Screens.push_back(&s1);
    screen_2 s2;
    Screens.push_back(&s2);

    while (screen >= 0){
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}

