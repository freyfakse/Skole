//
// Created by MORTEN on 16.11.2016.
//

#ifndef HM_PROJECT_FLYING_ENEMY_H
#define HM_PROJECT_FLYING_ENEMY_H

#include "../actor_class.h"
#include "../../config.h"
#include "../../Fysik/collision.h"
#include "../../Sound.h"

class Flying_enemy :public Actor_Class{
    Config conf;
public:
    sf::Music sound;
    sf::RectangleShape corrupt_file;
    Flying_enemy(sf::RenderWindow& window, Collision col, int xInn, int yInn, Config& conf) ; //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    Collision col;

    void move();
    void jump();
    void draw();
    void death();
};


#endif //HM_PROJECT_FLYING_ENEMY_H
