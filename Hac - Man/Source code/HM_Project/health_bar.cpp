//
// Created by MORTEN on 08.12.2016.
//

#include "health_bar.h"



health_bar::health_bar(sf::RenderWindow& window, Config& conf) : vindu(window), conf(conf) {


    if (!font.loadFromFile("Resources/arial.ttf"))
        //skriv in  hvis du har sat working directory til fonter + lydC:\\dev\\SFML\\lib\\ARDELANEY.ttf
    {
        std::cout << "failed to load font";
        // error
    }
    health.setFont(font);
    health.setCharacterSize(30);
    health.setStyle(sf::Text::Bold);
   // health.setColor(sf::Color::Green);
    health.setColor(sf::Color::Green);
    health.setString("test");

}

void health_bar::update(int lives,int boss) {

if(boss == -1) {

    temp = "lives :" + std::to_string(lives);
} else{
    temp = "lives :" + std::to_string(lives) +"   boss:" + std::to_string(boss);;
}
}




void health_bar::draw(int kameraPos, int kameraPosY) {
    health.setString(temp);
    health.setPosition(kameraPos+conf.windowWidth-300,kameraPosY);

    vindu.draw(health);
}