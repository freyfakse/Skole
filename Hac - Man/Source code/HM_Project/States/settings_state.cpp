//
// Created by Jonas on 24.10.2016.
//

#include "settings_state.h"
#include "menu_state.h"
//#include "Game_State.h"

Settings_State::Settings_State(sf::RenderWindow &window) : window(window) {


    sf::Font font;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect rectSourceSprite(0, 0, 323, 260);


    if (!texture.loadFromFile("Resources/background2NeonBlue.png")) {
        std::cout << "failed to load texture"; //error
    }

    sf::Sprite background(texture);
    background.setScale(sf::Vector2f(3.3, 2.14));




    // Declare and load a font
    font.loadFromFile("Resources/pix.ttf");
    // Run the game loop as long as the window is open
    while (window.isOpen()) {
        sf::Event event;

        // Read all events from the window
        while (window.pollEvent(event)) {
            // Quit when the user presses 'x', ignore all other events
            if (event.type == sf::Event::Closed)
                window.close();
        }


        RECT desktop;
        // Get a handle to the desktop window
        const HWND hDesktop = GetDesktopWindow();
        // Get the size of screen to the variable desktop
        GetWindowRect(hDesktop, &desktop);
        // The top left corner will have coordinates (0,0)
        // and the bottom right corner will have coordinates
        // (horizontal, vertical)
        int horizontal1 = desktop.right;
        int vertical1 = desktop.bottom;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //Apply settings changes
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            return;

        }
        if (clock.getElapsedTime().asSeconds() > 0.03f) {


            if (rectSourceSprite.left >= 6137) {

                rectSourceSprite.left = 323;

            } else {
                rectSourceSprite.left += 323;

                background.setTextureRect(rectSourceSprite);
                clock.restart();
            }


            // Clear the window to black
            window.clear();
            window.draw(background);

            // Create a text
            sf::Text text3("Settings", font);
            text3.setCharacterSize(30);
            text3.setStyle(sf::Text::Bold);
            text3.setFillColor(sf::Color::Green);
            text3.setPosition(20, 10);

            sf::Text text("Window Width: ", font);
            text.setCharacterSize(20);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Green);
            text.setPosition(10, 75);

            sf::Text text2("Window Height: ", font);
            text2.setCharacterSize(20);
            text2.setStyle(sf::Text::Bold);
            text2.setFillColor(sf::Color::Green);
            text2.setPosition(10, 130);

            sf::Text text4("[Apply]", font);
            text4.setCharacterSize(25);
            text4.setStyle(sf::Text::Bold);
            text4.setFillColor(sf::Color::Green);
            text4.setPosition(10, 300);

            sf::Text text5("[B]ack", font);
            text5.setCharacterSize(25);
            text5.setStyle(sf::Text::Bold);
            text5.setFillColor(sf::Color::Green);
            text5.setPosition(200, 300);


            // Draw it
            window.draw(text3);
            window.draw(text);
            window.draw(text2);
            window.draw(text4);
            window.draw(text5);
            //window.draw(texthor);
           // window.draw(textver);

            // Flip the back buffer and front buffer, showing what was drawn
            window.display();
        }
    }
    return;
}
//void Settings_State::switchTo(){}