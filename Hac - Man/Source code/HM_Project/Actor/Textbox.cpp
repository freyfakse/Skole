//
// Created by MORTEN on 12.12.2016.
//

#include "Textbox.h"

Textbox::Textbox(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){


    height = 0;
    width =0;
    dir =0;


    standing_still =1;
    startX = xInn;
    startY = yInn;
    x = startX-600;
    y = startY;
    prevlocation.x = x;
    prevlocation.y = y;
    immunity = 1;
    floor = conf.windowHeight-32-height;
    speed = 1;
    rectSourceSprite = sf::IntRect(0,0,26,26);
    textbox.setFillColor(sf::Color::Black);
    textbox.setSize(sf::Vector2f(750, 200));



    font.loadFromFile("Resources/pix.ttf");
    text.setFont(font);
    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);
    text5.setFont(font);
    text.setCharacterSize(15);
    text1.setCharacterSize(15);
    text2.setCharacterSize(15);
    text3.setCharacterSize(15);
    text4.setCharacterSize(15);
    text5.setCharacterSize(15);


    text.setStyle(sf::Text::Bold);
    text1.setStyle(sf::Text::Bold);
    text2.setStyle(sf::Text::Bold);
    text3.setStyle(sf::Text::Bold);
    text4.setStyle(sf::Text::Bold);
    text5.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Green);
    text1.setColor(sf::Color::Green);
    text2.setColor(sf::Color::Green);
    text3.setColor(sf::Color::Green);
    text4.setColor(sf::Color::Green);
    text5.setColor(sf::Color::Green);
    text.setPosition(x, y);
    text1.setPosition(x, y+20);
    text2.setPosition(x, y+40);
    text3.setPosition(x, y+60);
    text4.setPosition(x, y+80);
    text5.setPosition(x, y+100);

}
void Textbox::move(){}

void Textbox::loadText(int select) {

    if(select == 0){
        text.setString("In the distant future of year 200X.");
        text1.setString("Evil is threatening the Internet and the world.");
        text2.setString("Are you a bad enough dude to save the Internet?");
        text3.setString("Take down the antivirus to get into the mainframe.");
        text4.setString("Use arrow keys to move, WASD to shoot." );
        text5.setString("Press space to continue the hacking.");
    }

    if(select == 1){
        text.setString("GG WP Hac-Man, you defeated the evil antiAntivirus.");
        text1.setString("We are now one level deeper in the web.");
        text2.setString("Keep it up and you might hack us some hope.");
        text3.setString("But beware, the Evil tm are on to us.");
        text4.setString("We have to deliver the payload!" );
        text5.setString("Press space to continue the hacking.");
    }

    if(select == 2){
        text.setString("Congratulation you saved The Internet");
        text1.setString("Developers & artists: Audun Borgersen, Jonas Claesson,");
        text2.setString("Morten Grundetjern, Tore Lam,");
        text3.setString("Lars Ryntveit & Tor Halvard Svendsen");
        text4.setString("Special thanks: Espen Grundetjern for art.");
        text5.setString("Music: freesound.org");
    }

    if(select == 3){
        text.setString("We might need two keyboards for this one.");
        text1.setString("The super mainframe server is just ahead.");
        text2.setString("Deliver the payload and this will be over.");
        text3.setString("They are throwing everything they have at us now.");
        text4.setString("Hack the planet!");
        text5.setString("Press space to continue the hacking.");
    }
}

void Textbox::draw(){

    textbox.setPosition(sf::Vector2f(x-10,y-10));
    vindu.draw(textbox);
    vindu.draw(text);
    vindu.draw(text1);
    vindu.draw(text2);
    vindu.draw(text3);
    vindu.draw(text4);
    vindu.draw(text5);
}

void Textbox::interaction( std::vector<Actor_Class*> actor_array){

    for (int i = 0; i <actor_array.size() ; ++i) {
        if(actor_array[i]->actorid == 1){

            actor_array[i]->setX(actor_array[i]->prevlocation.x);
            actor_array[i]->setY(actor_array[i]->prevlocation.y);
            actor_array[i]->dir =-1;
            actor_array[i]->speed =0;
            actor_array[i]->rectSourceSprite.top = 0;
            actor_array[i]->action_taken = -2;


        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {lifeState = 0;
            actor_array[i]->speed =5;
            actor_array[i]->action_taken =-1;
        }
    }
}

void Textbox::jump(){}
void Textbox::death() {}
