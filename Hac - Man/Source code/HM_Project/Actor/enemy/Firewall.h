//
// Created by MORTEN on 16.11.2016.
//

#ifndef HM_PROJECT_FIREWALL_H
#define HM_PROJECT_FIREWALL_H

#include "../actor_class.h"
#include "../../Fysik/collision.h"


class Firewall : public Actor_Class {
  Config conf;
public:
    sf::RectangleShape firewall;
    Firewall(sf::RenderWindow& window, Collision col, int xInn, int yInn,int length) ; //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    Collision col;
    int mylength;

    void move();
    void jump();
    void draw();
    void death();
    void interaction_effect(Actor_Class* actor);
    void interaction( std::vector<Actor_Class*> actor_array);
};


#endif //HM_PROJECT_FIREWALL_H
