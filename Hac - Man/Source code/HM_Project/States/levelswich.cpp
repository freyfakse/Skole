//
// Created by MORTEN on 06.12.2016.
//

#include "levelswich.h"
#include "Pause_State.h"
#include "game_state.h"
#include "menu_state.h"
#include "selectlvl_state.h"

levelswich::levelswich(sf::RenderWindow &window,int kameraPos, int kameraPosY,int level,int previuslevel, sf::View& camera) :window(window)
{

    sf::Clock clock;
    sf::Texture texture;
    sf::Font font;

    font.loadFromFile("Resources/pix.ttf");
    camera.reset(sf::FloatRect(0,0, window.getSize().x, window.getSize().y));
    sf::IntRect rectSourceSprite(0,0,323,260);

    // Declare and load a background
    if (!texture.loadFromFile("Resources/background2NeonRed.png"))
    {
        std::cout << "failed to load texture"; //error
    }
     sf::Sprite backgroundlvl(texture);
    backgroundlvl.setScale(sf::Vector2f(3.3, 2.14));

    font.loadFromFile("Resources/pix.ttf");

    sf::Text text5("Press Space to continue Hacking", font);
    sf::Text text3("Select level", font);
    sf::Text text4("Quit Hack", font);
    sf::Text text;
    if(level != previuslevel){
        text = sf::Text("You hacket the level!", font);

        // Declare and load a background
        if (!texture.loadFromFile("Resources/background2NeonBlue.png"))
        {
            std::cout << "failed to load texture"; //error
        }
        sf::Sprite backgroundlvl(texture);
        backgroundlvl.setScale(sf::Vector2f(3.3, 2.14));



    }
    else{

        // Declare and load a background
        if (!texture.loadFromFile("Resources/background2NeonRed.png"))
        {
            std::cout << "failed to load texture"; //error
        }
        sf::Sprite backgroundlvl(texture);
        backgroundlvl.setScale(sf::Vector2f(3.3, 2.14));
        text = sf::Text("You got counter-hacked!", font);


    }




    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(window.getSize().x / 1.9, window.getSize().y / 8.1);

    text5.setOrigin(text5.getGlobalBounds().width / 2, text5.getGlobalBounds().height / 2);
    text5.setPosition(window.getSize().x / 1.6, window.getSize().y / 8 + 4 * text.getGlobalBounds().height*1.0f);

    text3.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text3.setPosition(window.getSize().x / 1.75, window.getSize().y / 8 + 6 * text.getGlobalBounds().height*1.0f);

    text4.setOrigin(text4.getGlobalBounds().width / 2, text4.getGlobalBounds().height / 2);
    text4.setPosition(window.getSize().x /1.75, window.getSize().y / 8 + 8 * text.getGlobalBounds().height*1.0f);


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Quit when the user presses 'x', ignore all other events
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->downKey) {
                this->selected += 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->upKey) {
                this->selected -= 1;
            }

            if (this->selected > 1){
                this->selected = 0;
            }

            if (this->selected < 0){
                this->selected = 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
                if(selected == 0){
                    selectlvl_state lvl(window,-1);
                    this->level = lvl.level;
                    this->stateid = 1;
                    camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
                    return;
                }
                if(selected == 1){

                    window.close();
                    camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
                    return;
                }
            }
            this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
            this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            this->stateid = 1;
            this->level = level;
            camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
            return;
        }
        ///should be 0.05f for smooth frames - test on 0.3f


        if(clock.getElapsedTime().asSeconds() >0.03f){


            if (rectSourceSprite.left >= 6137) {

                rectSourceSprite.left = 323;

            }
            else{
                rectSourceSprite.left += 323;

                backgroundlvl.setTextureRect(rectSourceSprite);
                clock.restart();
            }

        }


        window.clear();
        window.setView(camera);

        //Tekst i pausemenyen


        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Green);




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
                text3.setFillColor(sf::Color::White);
                break;
            case 1:
                text4.setFillColor(sf::Color::White);
                break;
        }

        window.draw(backgroundlvl);
        window.draw(text);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);

        //tekst slutt

        window.display();
    }
    camera.reset(sf::FloatRect(kameraPos, kameraPosY, window.getSize().x, window.getSize().y));
    return;
}

void levelswich::switchTo() {}