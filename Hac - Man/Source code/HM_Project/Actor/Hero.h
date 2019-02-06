//
// Created by kab95 on 18.10.2016.
//

#ifndef HM_PROJECT_HERO_H
#define HM_PROJECT_HERO_H
//midlertidig for testing
#include "iostream"
#include "../Sound.h"
#include "actor_class.h"
#include "../Fysik/collision.h"
#include "../Tile/Tilemap.h"
#include "animatonsprites.h"



class Hero : public Actor_Class{

public:

    animatonsprites animation;
    sf::RectangleShape helt;
    /// makes a hero characther that the player can control
    /// \param window defines the window where the hero is drawn
    /// \param col is the collision detection function that the hero uses
    /// \return
    Hero(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
    sf::RenderWindow& vindu;
/*(0,0,450,240)*/;

    //sf::Sprite testsprite/*(texture, rectSourceSprite)*/;


    //float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title
    //float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title


    /// makes the hero jump

    int jumpVar = 0;
    int startX = 20;
    int startY = 100;

    Collision col;
    Sound sounds;
    Config conf;

    int mutecheck = 0; //sjekker om lyden er muted
    void jump();
    ///makes the hero move
    void move(); //flytter karakteren med piltaster
    /// draws the hero
    void draw(); //tegner i importert vindu
    ///kills the hero


    void death();
    void respawn();


};


#endif //HM_PROJECT_HERO_H
