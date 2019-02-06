//
// Created by MORTEN on 13.12.2016.
//

#include "selectlvl_state.h"

selectlvl_state::selectlvl_state(sf::RenderWindow &window,int current) : window(window) {

    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){} //prevents the user form accidentally running through selectlvl by holding enter for too long.

    this->selected = 0;

    sf::Font font;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect rectSourceSprite(0,0,323,260);

    // Declare and load a font
    if (!font.loadFromFile("Resources/pix.ttf")) {
        std::cout << "failed to load font"; // error
    }
    // Declare and load a background
    if (!texture.loadFromFile("Resources/background2NeonPink.png")) {
        std::cout << "failed to load texture"; //error
    }
    sf::Sprite background(texture);
    background.setTextureRect(rectSourceSprite);
    background.setScale(sf::Vector2f(3.3, 2.14));

    title= sf::Text("Select level", font);
    text = sf::Text("Level 1: ", font);
    text2= sf::Text("Level 2: ", font);
    text3= sf::Text("Level 3: ", font);
    text4= sf::Text("Level 4:", font);
    text5= sf::Text("Level 5:", font);
    text6= sf::Text("Level 6:", font);
    text7= sf::Text("Back", font);

    title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
    title.setPosition(window.getSize().x / 2.4, window.getSize().y / 8);

    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(window.getSize().x / 1.78, window.getSize().y / 8 + 3 * title.getGlobalBounds().height * 0.75f);

    text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height / 2);
    text2.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 4.5 * title.getGlobalBounds().height * 0.75f);

    text3.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text3.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 6 * title.getGlobalBounds().height * 0.75f);

    text4.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text4.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 7.5 * title.getGlobalBounds().height * 0.75f);

    text5.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text5.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 9 * title.getGlobalBounds().height * 0.75f);


    text6.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text6.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 10.5 * title.getGlobalBounds().height * 0.75f);

    text7.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text7.setPosition(window.getSize().x /1.75, window.getSize().y / 8 + 12 * title.getGlobalBounds().height * 0.75f);


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->downKey) {
                this->selected += 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->upKey) {
                this->selected -= 1;
            }

            if (this->selected > 6) {
                this->selected = 0;
            }

            if (this->selected < 0) {
                this->selected = 6;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
                if(selected == 6){

                    this->stateid = current;
                    this->level = -1;
                    return ;
                }
                else{
                    this->stateid = 1;
                    this->level = selected;
                }
                return;
            }


            //Create text

            title.setCharacterSize(50);
            title.setStyle(sf::Text::Bold);
            title.setFillColor(sf::Color::Green);


            text.setCharacterSize(15);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Green);


            text2.setCharacterSize(15);
            text2.setStyle(sf::Text::Bold);
            text2.setFillColor(sf::Color::Green);


            text3.setCharacterSize(15);
            text3.setStyle(sf::Text::Bold);
            text3.setFillColor(sf::Color::Green);



            text4.setCharacterSize(15);
            text4.setStyle(sf::Text::Bold);
            text4.setFillColor(sf::Color::Green);



            text5.setCharacterSize(15);
            text5.setStyle(sf::Text::Bold);
            text5.setFillColor(sf::Color::Green);



            text6.setCharacterSize(15);
            text6.setStyle(sf::Text::Bold);
            text6.setFillColor(sf::Color::Green);



            text7.setCharacterSize(20);
            text7.setStyle(sf::Text::Bold);
            text7.setFillColor(sf::Color::Green);



            switch (this->selected) {
                case 0:
                    text.setFillColor(sf::Color::White);
                    break;
                case 1:
                    text2.setFillColor(sf::Color::White);
                    break;
                case 2:
                    text3.setFillColor(sf::Color::White);
                    break;
                case 3:
                    text4.setFillColor(sf::Color::White);
                    break;
                case 4:
                    text5.setFillColor(sf::Color::White);
                    break;
                case 5:
                    text6.setFillColor(sf::Color::White);
                    break;
                case 6:
                    text7.setFillColor(sf::Color::White);
                    break;
            }


            // Draw it
/*
            window.draw(title);
            window.draw(text);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);
            window.draw(text6);
            window.draw(text7);
*/

            // Flip the back buffer and front buffer, showing what was drawn


        }
        if(clock.getElapsedTime().asSeconds() >0.03f){


            if (rectSourceSprite.left >= 6137) {

                rectSourceSprite.left = 323;

            }
            else{
                rectSourceSprite.left += 323;

                background.setTextureRect(rectSourceSprite);
                clock.restart();
            }

        }
        if(clock.getElapsedTime().asSeconds() >0.03f){


            if (rectSourceSprite.left >= 6137) {

                rectSourceSprite.left = 323;

            }
            else{
                rectSourceSprite.left += 323;

                background.setTextureRect(rectSourceSprite);
                clock.restart();
            }

        }


        window.clear();
       // window.setView(camera);
        window.draw(background);
        window.draw(title);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
       // window.draw(background);
        window.display();

    }
    return;
}

//void selectlvl_state::switchTo() {}
