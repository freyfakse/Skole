//
// Created by Jonas on 02.11.2016.
//

#include "Pause_State.h"
#include "game_state.h"
#include "selectlvl_state.h"

Pause_State::Pause_State(sf::RenderWindow &window,int kameraPos, int kameraPosY, sf::View& camera) :window(window)
{
    isEscPressed = true;
    this->selected = 0;

    sf::Font font;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect rectSourceSprite(0,0,323,260);

    //pause menyen følge kameraet og ikkje stuck i begynnelsen.
    camera.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

    // Declare and load a background
    if (!texture.loadFromFile("Resources/background2NeonPink.png"))
    {
        std::cout << "failed to load texture"; //error
    }

    sf::Sprite background(texture);
    background.setScale(sf::Vector2f(3.3, 2.14));
    //load font
    font.loadFromFile("Resources/pix.ttf");


    sf::Text text("Paused", font);
    sf::Text text2("Resume", font);

    sf::Text text5("Select level", font);
    sf::Text text3("Exit to menu", font);
    sf::Text text4("Quit the Hack", font);

    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(window.getSize().x / 2.1, window.getSize().y / 8.2);

    text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height / 2);
    text2.setPosition(window.getSize().x / 1.8, window.getSize().y / 8 + 3 * text.getGlobalBounds().height*1.0f);

    text5.setOrigin(text5.getGlobalBounds().width / 2, text5.getGlobalBounds().height / 2);
    text5.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 7 * text.getGlobalBounds().height*0.75f);

    text3.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text3.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 9 * text.getGlobalBounds().height*0.75f);

    text4.setOrigin(text4.getGlobalBounds().width / 2, text4.getGlobalBounds().height / 2);
    text4.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 11 * text.getGlobalBounds().height*0.75f);


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Quit when the user presses 'x', ignore all other events
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->downKey) {
            this->selected += 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->upKey) {
            this->selected -= 1;
        }

        if (this->selected > 3){
            this->selected = 0;
        }

        if (this->selected < 0){
            this->selected = 3;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){

            if(selected == 0){ //resume the game
                this->stateid = -1;
                camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
                return;
            }
            if(selected == 1){ //restart
                //this->stateid = 1;

                selectlvl_state lvl(window,-1);
                this->level = lvl.level;
                this->stateid = lvl.stateid;
                camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
                return;
            }
            if(selected == 2){ //menu

                camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));

                return;
            }
            //midlertidig close -> switch sound on off

            if(selected == 3){ //close
                window.close();
            }//back to menu

        }
        this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

        window.clear();
        window.setView(camera);

        //Tekst i pausemenyen


        text.setCharacterSize(50);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Green);



        text2.setCharacterSize(20);
        text2.setStyle(sf::Text::Bold);
        text2.setFillColor(sf::Color::Green);



        text5.setCharacterSize(20);
        text5.setStyle(sf::Text::Bold);
        text5.setFillColor(sf::Color::Green);



        text3.setCharacterSize(20);
        text3.setStyle(sf::Text::Bold);
        text3.setFillColor(sf::Color::Green);



        text4.setCharacterSize(20);
        text4.setStyle(sf::Text::Bold);
        text4.setFillColor(sf::Color::Green);


        switch (this->selected){
            case 0:
                text2.setFillColor(sf::Color::White);
                break;
            case 1:
                text5.setFillColor(sf::Color::White);
                break;
            case 2:
                text3.setFillColor(sf::Color::White);
                break;
            case 3:
                text4.setFillColor(sf::Color::White);
                break;
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

        window.draw(background);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);

        //tekst slutt

        window.display();
    }
    camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
    return;
}

void Pause_State::switchTo() {}
