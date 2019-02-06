//
// Created by MORTEN on 09.12.2016.
//

#ifndef HM_PROJECT_BOSS_FIGHT_3_H
#define HM_PROJECT_BOSS_FIGHT_3_H




#include <SFML/Graphics.hpp>
#include "../actor_class.h"
#include "../../Fysik/collision.h"
#include "../../Sound.h"
#include "../animatonsprites.h"

class boss_fight_3 : public Actor_Class{

    Config conf;
    //Sound sound;

public:
    sf::RectangleShape boss;
    animatonsprites animaton;
    boss_fight_3(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
    Collision col;

    float gravity = 5;


    int startX=400;
    int startY=20;
    int boss_jump = 50;
    int boss_shoot = 5;
    int movment =0;
    int random  =50;
    int random2 =100;
    int random3 =200;
    int bullet = 1;
    int tempdir;
    int wallhitcounter =0;


    void jump();
    void move(); //flytter karakteren
    void moveswicher(int* move);
    void draw(); //tegner i importert vindu
    void action();
    void death();
};




#endif //HM_PROJECT_BOSS_FIGHT_3_H
