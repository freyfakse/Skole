//
// Created by MORTEN on 25.10.2016.
//
#include "game_timer.h"
Game_Timer::Game_Timer(sf::RenderWindow& window) : vindu(window) {


    if (!font.loadFromFile("Resources/arial.ttf"))
        //skriv in  hvis du har sat working directory til fonter + lydC:\\dev\\SFML\\lib\\ARDELANEY.ttf
    {
        std::cout<<"failed to load font";
        // error
    }
    Game_time.setFont(font);
    Game_time.setCharacterSize(30);
    Game_time.setStyle(sf::Text::Bold);
    Game_time.setFillColor(sf::Color::Green);
    Game_time.setFillColor(sf::Color::Blue);
    Game_time.setString("test");

}
void Game_Timer::teller() {

    temp =std::to_string((int)clock.getElapsedTime().asSeconds());

}
void Game_Timer::draw(int kameraPos, int kameraPosY) {
    Game_time.setString(temp);
    Game_time.setPosition(kameraPos,kameraPosY);

    vindu.draw(Game_time);
}