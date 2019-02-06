//
// Created by MORTEN on 09.12.2016.
//

#ifndef HM_PROJECT_HEALTH_ITEM_H
#define HM_PROJECT_HEALTH_ITEM_H


#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"








    class health_item : public Actor_Class{
        Config conf;

    public:
        sf::RectangleShape heart;
        health_item(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
        sf::RenderWindow& vindu;
        Collision col;

        float gravity = 5;

        ///float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title

        // float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title

        int startX=400;
        int startY=20;

        void interaction_effect(Actor_Class* actor);
        void jump();
        void move(); //flytter karakteren
        void draw(); //tegner i importert vindu
        void death();
    };




#endif //HM_PROJECT_HEALTH_ITEM_H
