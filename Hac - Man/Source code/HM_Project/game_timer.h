//
// Created by MORTEN on 25.10.2016.
//

#ifndef HM_PROJECT_GAME_TIMER_H
#define HM_PROJECT_GAME_TIMER_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Super_Class.h"

class Game_Timer: public Super_Class {

protected:
    sf::Clock clock;
    int timer;
    sf::RenderWindow& vindu;
    std::string temp;
    bool paused = false;

public:
    Game_Timer(sf::RenderWindow& window);
    void teller();
    void draw(int kameraPos, int kameraPosY);
    sf::Text Game_time;
    sf::Font font;
};


#endif //HM_PROJECT_GAME_TIMER_H
