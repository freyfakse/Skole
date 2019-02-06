//
// Created by MORTEN on 12.12.2016.
//

#ifndef HM_PROJECT_TEXTBOX_H
#define HM_PROJECT_TEXTBOX_H


#include <SFML/Graphics.hpp>
#include "actor_class.h"
#include "../Fysik/collision.h"



class Textbox : public Actor_Class{
        Config conf;
        //Sound sound;

    public:

    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    sf::Font font;


        sf::RectangleShape textbox;
        Textbox(sf::RenderWindow& window, Collision col, int xInn, int yInn); //Henter inn referanse til vindu for å unngå å lage et nytt vindu for hver state.
        sf::RenderWindow& vindu;
        Collision col;



        ///float floor =400;//bør byttes ut med at det er localisasjonen den intersecter med en title

        // float floor =224;//bør byttes ut med at det er localisasjonen den intersecter med en title

        int startX=400;
        int startY=20;
        void loadText(int select );
        void jump();
        void move(); //flytter karakteren
        void draw(); //tegner i importert vindu
        void death();
        void interaction( std::vector<Actor_Class*> actor_array);
    };




#endif //HM_PROJECT_TEXTBOX_H
