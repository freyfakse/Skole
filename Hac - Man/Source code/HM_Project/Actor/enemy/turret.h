//
// Created by Jonas on 08.12.2016.
//

#ifndef HM_PROJECT_TURRET_H
#define HM_PROJECT_TURRET_H

#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"
#include "../../config.h"
#include "../animatonsprites.h"

class turret : public Actor_Class{
    Config conf;

public:
    sf::RectangleShape turrets;
    turret(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    animatonsprites animation;
    Collision col;

    float gravity = 5;

    int boss_shoot = 5;

    ///float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title

    // float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title

    int startX=400;
    int startY=20;

    void jump();
    void move(); //flytter karakteren
    void draw(); //tegner i importert vindu
    void death();
    void action(){};
    virtual void interaction( std::vector<Actor_Class*> actor_array);
};


#endif //HM_PROJECT_TURRET_H
