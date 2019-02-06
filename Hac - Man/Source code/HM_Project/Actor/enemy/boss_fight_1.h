//
// Created by MORTEN on 18.11.2016.
//

#ifndef HM_PROJECT_BOSS_FIGHT_1_H
#define HM_PROJECT_BOSS_FIGHT_1_H


#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"
#include "../../Sound.h"

class boss_fight_1 : public Actor_Class{

    Config conf;
    //Sound sound;

public:
   // sf::Music sound;
    sf::RectangleShape boss;
    boss_fight_1(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    Collision col;

    float gravity = 5;

    ///float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title

   // float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title

    int startX=400;
    int startY=20;
    int boss_jump = 50;
    int boss_shoot = 5;


    void jump();
    void move(); //flytter karakteren
    void draw(); //tegner i importert vindu
    void action();
    void death();
};





#endif //HM_PROJECT_BOSS_FIGHT_1_H
