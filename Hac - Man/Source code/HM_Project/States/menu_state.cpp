//
// Created by kab95 on 18.10.2016.
//

#include "menu_state.h"
#include "selectlvl_state.h"


 menu_state::menu_state(sf::RenderWindow &window, sf::View& camera) :window(window)
{
        Config conf;

        this->selected = 0;


        // Enable vertical sync - prevents tearing and locks framerate to display
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(120);


        sf::Texture texture;
        texture.loadFromFile("Resources/background2NeonPink.png");

    sf::IntRect rectSourceSprite(0,0,323,260);
    sf::Sprite testsprite(texture, rectSourceSprite);
    testsprite.setScale(sf::Vector2f(3.3, 2.14));

        sf::Clock clock;
        camera.reset(sf::FloatRect(0,0,conf.windowWidth,conf.windowHeight));

        sf::Font font;

    sf::Music introMusic;
    introMusic.openFromFile("Resources/intro_3.wav");
    introMusic.setLoop(true);
    introMusic.play();

        if (!font.loadFromFile("Resources/pix.ttf"))
        //skriv in arial.ttf hvis du har sat working directory til fonter + lyd
        {
            std::cout<<"failed to load font";
            // error
        }

    sf::Text title("Hac-Man", font);
    sf::Text text4("Story Mode", font);
    sf::Text text("Select Level", font);
    sf::Text text2("Settings", font);
    sf::Text text3("Quit", font);

    title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
    title.setPosition(window.getSize().x / 2.28, window.getSize().y / 8);


    text4.setOrigin(text4.getGlobalBounds().width / 2, text4.getGlobalBounds().height / 2);
    text4.setPosition(window.getSize().x / 2, window.getSize().y / 8 + 3 * title.getGlobalBounds().height*1.25f);

    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 8 + 4.5 * title.getGlobalBounds().height*1.25f);

    text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height / 2);
    text2.setPosition(window.getSize().x / 2, window.getSize().y / 8 + 6 * title.getGlobalBounds().height*1.25f);

    text3.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text3.setPosition(window.getSize().x / 2, window.getSize().y / 8 + 7.5 * title.getGlobalBounds().height*1.25f);
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
                if(selected == 0){
                    this->level = 0;
                    this->stateid = 1;
                    return;
                }
                    if(selected == 1){
                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
                            selectlvl_state lvl(window,stateid);
                            this->level = lvl.level;
                            this->stateid = lvl.stateid;

                            return;
                        }
                    }

                if(selected == 2)
                Settings_State set(window);


                if(selected == 3)
                    window.close();


            }
            this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
            this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        }

        //sf::Time frameTime = frameClock.restart();
        ///should be 0.05f for smooth frames - test on 0.3f


        if(clock.getElapsedTime().asSeconds() >0.03f){


            if (rectSourceSprite.left >= 6137) {

                rectSourceSprite.left = 323;

            }
            else{
                rectSourceSprite.left += 323;

                testsprite.setTextureRect(rectSourceSprite);
                clock.restart();
            }

        }

        // Clear the window to black
        window.clear();
        window.setView(camera);
        window.draw(testsprite);

        // Create a text

        title.setCharacterSize(50);
        title.setStyle(sf::Text::Bold);
        title.setFillColor(sf::Color::Green);
        title.setFillColor(sf::Color::Green);



        text4.setCharacterSize(30);
        text4.setStyle(sf::Text::Bold);
        text4.setFillColor(sf::Color::Green);

        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Green);

        text2.setCharacterSize(30);
        text2.setStyle(sf::Text::Bold);
        text2.setFillColor(sf::Color::Black);

        text3.setCharacterSize(30);
        text3.setStyle(sf::Text::Bold);
        text3.setFillColor(sf::Color::Green);


        switch (this->selected){
            case 0:
                text4.setFillColor(sf::Color::White);
                break;
            case 1:
                text.setFillColor(sf::Color::White);
                break;
            case 2:
                text2.setFillColor(sf::Color::White);
                break;
            case 3:
                text3.setFillColor(sf::Color::White);
                break;
        }

        // Draw text
        window.draw(title);
        window.draw(text);
        window.draw(text4);
        window.draw(text2);
        window.draw(text3);

        // Flip the back buffer and front buffer, showing what was drawn
        window.display();
    }
    return;
}

//void menu_state::switchTo() {}