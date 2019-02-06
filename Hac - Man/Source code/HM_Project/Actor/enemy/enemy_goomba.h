//
// Created by kab95 on 20.10.2016.
//

#ifndef HM_PROJECT_ENEMY_GOOMBA_H
#define HM_PROJECT_ENEMY_GOOMBA_H

#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"
#include "../animatonsprites.h"
//#include "../../Sound.h"

class Enemy_Goomba : public Actor_Class{
    Config conf;

public:
    sf::Music sound;
    animatonsprites animation;
    sf::RectangleShape goomba;
    Enemy_Goomba(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    Collision col;

    float gravity = 5;

    ///float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title

   // float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title

    int startX=400;
    int startY=20;

    void jump();
    void move(); //flytter karakteren
    void draw(); //tegner i importert vindu
    void death();
};


#endif //HM_PROJECT_ENEMY_GOOMBA_H
