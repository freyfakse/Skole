//
// Created by MORTEN on 07.12.2016.
//

#ifndef HM_PROJECT_BOSS_DOOR_H
#define HM_PROJECT_BOSS_DOOR_H

#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"
#include "../animatonsprites.h"



class Boss_door :public Actor_Class{

    Config conf;

public:
    sf::RectangleShape door;
    animatonsprites animation;
    Boss_door(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
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
    void interaction( std::vector<Actor_Class*> actor_array);
    void interaction_effect(Actor_Class* actor);
    void death();
};





#endif //HM_PROJECT_BOSS_DOOR_H
