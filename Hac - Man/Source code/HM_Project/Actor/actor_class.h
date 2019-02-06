//
// Created by kab95 on 20.10.2016.
//

#ifndef HM_PROJECT_ACTOR_CLASS_H
#define HM_PROJECT_ACTOR_CLASS_H
#include "../Super_Class.h"
#include <SFML/Graphics.hpp>



class Actor_Class : public Super_Class {

public:
    sf::Texture spriteTexture;//en artifakt gammelkode
    sf::Texture texture;//spritshettet blir lastet inn i teksturen som blir git til player image
    sf::Sprite playerImage;// spriten som blir tegnet opp
    sf::Clock Playerclock;//en klokke som indikerer når vi skal bytte animasjon
    sf::IntRect rectSourceSprite;//en firkant som sier hvilket område av spritsheten som skal tegnes opp

    int lvl =0;//brukes i hero som blir gitt til levelselect som bruker denne til å fortelle gamstate hvilken level den skal laste inn  når gamestate starter opp
    int actorid =0;// brukes for å gjenkjenne actors
    int height;// høyden på hitboksen
    int width;//widden på hitboksen
    int imortal = 0;//brukes for å lage frames der spilleren ikke kan ta skade
    sf::Vector2f prevlocation; // brukess for å huske forige lokalison brukes i collisiondetection og der vi trenger en effekt som kan blokkere en aktor
    int falling = 0; //sier om actoren faller
    int standing_still;//sier om den står stille brukes i animasjonen
    int dir;//foteller hviken vei en actor går
    int direction = 0;//brukes for å finne ut hvilken vei en actor skyter
    int action_taken = -1;//if action taken is 1 shot
    bool roof;// flyve finden bruker denne for å sjekke om den treffer taket

    int health = 1;// livet til bosser
    int immunity;// er en variabel som angir hva som kan gi skade til en actor
    int lifeState = 1; // hvis denne variabelen blir til 0 sletes/dør en actor i spillet
    int floor = 400;//ble brukt tidlig i koden for å lage et gulv
    float gravity = 5;// denne variablen gjør at actorer faller nedover
    float speed = 1;// denne angir farten som en actor kan bevege seg med
    int maxSpeed = speed*4;// når en actor er påvirket av foreksempel en speed tile så angir den maxspeeden den actoren kan oppnå
    int minSpeed = speed;// når en actor mister speed etter at den har kommet av en speed tile så angir denne minste speed den får
    double spriteHeight = 2.5; // envariabel som brukes noen plasser for å scalere bilders høyde
    double spriteWidth = 2.5;// envariabel som brukes noen plasser for å scalere bilders bredden


    virtual void move();// en function som actorene bruker for å forflytte seg  i x aksen noen untak
    virtual void draw();// en function som actorene bruker for å bli tegnet opp
    virtual void jump(); //en function som actorene bruker for å forflytte seg i y aksen
    virtual void action();//en function som actorene bruker for å skyte
    virtual void interaction( std::vector<Actor_Class*> actor_array){};//en function som actorene bruker for å få informasjon om andre actorer i spillet
    virtual void interaction_effect(Actor_Class* actor){};//en function som actorene bruker for å få gi en effekt på en koliderene actor
    virtual void death();// en function som fjerner liv eller setter lifestate til 0 slik at actoren blir slettet


};


#endif //HM_PROJECT_ACTOR_CLASS_H
