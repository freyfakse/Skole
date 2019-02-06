//
// Created by Jonas on 16.11.2016.
//

#include "Window_State.h"
#include "../config.h"
#include "menu_state.h"

Window_State::Window_State()
{
    switchTo();
}

void Window_State::switchTo() {
    Config conf;
    sf::RenderWindow window(sf::VideoMode(conf.windowWidth, conf.windowHeight), "Hac - Man");
    sf::View camera;

    // Enable vertical sync - prevents tearing and locks framerate to display
    window.setVerticalSyncEnabled(true);

    // Run the game loop as long as the window is open
    while (window.isOpen()) {
        sf::Event event;

        // Read all events from the window
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (this->stateid == 0) {
            menu_state menu(window, camera);
            this->stateid = menu.stateid;
            this->level = menu.level;

        }

        if (stateid == 1) {
            Game_State ny(window, level,conf, camera);
            this->stateid = ny.stateid;
            this->level = ny.level;

        }
     /*   if (stateid == 2) {
             ny(window, -1);
            this->stateid = ny.stateid;

        }*/



    }
    return;
}

/*

void Menu_State::switchTo(){
    // Create a window we can draw to
    Config conf;
    sf::RenderWindow window(sf::VideoMode(conf.windowWidth, conf.windowHeight), "Hac - Man");

    // Enable vertical sync - prevents tearing and locks framerate to display
    window.setVerticalSyncEnabled(true);

    // Run the game loop as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;

        // Read all events from the window
        while (window.pollEvent(event))
        {
            // Quit when the user presses 'x', ignore all other events
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            {
                chooser = 1;
                //std::cout<<"du har trykket paa p"<<std::endl;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                chooser = 2;
                //std::cout<<"du har trykket paa s"<<std::endl;
            }
        }

        // Clear the window to black
        window.clear();

        //Set font
        sf::Font font;

        if (!font.loadFromFile("arial.ttf"))
            //skriv in arial.ttf hvis du har sat working directory til fonter + lyd
        {
            std::cout<<"failed to load font";
            // error
        }

        // Create a text
        sf::Text text3("Main Menu", font);
        text3.setCharacterSize(50);
        text3.setStyle(sf::Text::Bold);
        text3.setFillColor(sf::Color::Green);
        text3.setPosition(20, 10);

        sf::Text text("[P]lay", font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Green);
        text.setPosition(0, 60);

        sf::Text text2("[S]ettings", font);
        text2.setCharacterSize(30);
        text2.setStyle(sf::Text::Bold);
        text2.setFillColor(sf::Color::Green);
        text2.setPosition(0, 90);

        if(chooser == 1)
        {
            Game_State ny(window); //Midlertidig overføring til Game_State. kan slettes.
        }

        if(chooser == 2)
        {
            Settings_State set(window);
        }

        // Draw text
        window.draw(text3);
        window.draw(text);
        window.draw(text2);

        // Flip the back buffer and front buffer, showing what was drawn
        window.display();
    }

    */

