//
// Created by MORTEN on 16.11.2016.
//
#include "Firewall.h"
#include "../actor_class.h"
#include "../../config.h"
#include "../../Fysik/collision.h"


Firewall::Firewall(sf::RenderWindow& window, Collision col,int xInn ,int yInn, int length) : vindu(window), col(col){

    height = conf.windowHeight;
    width = 80;
    dir =1;
    mylength = length;


    spriteWidth = 0.8;
    spriteHeight = 3;
    x = 0;
    y = 0;
    immunity = 2;

    floor = conf.windowHeight-32-height;
    speed = 2;
    actorid = 92;


    firewall.setFillColor(sf::Color::Red);
    firewall.setSize(sf::Vector2f(width, height));

    ///ensures that the hero texture has been loaded
    if(!spriteTexture.loadFromFile("Resources/FirewallV2.png", sf::IntRect(0,0,600,500)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }
    texture.loadFromFile("Resources/FirewallV2.png");

    playerImage.setTexture(texture);

    //helt.setPosition(x, y);
    //helt.setFillColor(sf::Color::Red);
    //helt.setSize(sf::Vector2f(width, height));
    playerImage.setPosition(x, y);
    //helt.setFillColor(sf::Color::Red);
    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));

}
void Firewall::move(){

    x +=speed;

    if(x == mylength*32 ){
        lifeState = 0;
    }

}


void Firewall::interaction(std::vector<Actor_Class *> actor_array) {

if(actor_array[0]->getX()<this->getX()){
    actor_array[0]->lifeState=0;
}


}
void Firewall::draw(){
    firewall.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x-64 ,y-60));
    vindu.draw(playerImage);
}
void Firewall::jump(){

}
void Firewall::death() {


   // lifeState = 0;
}
void Firewall::interaction_effect(Actor_Class* actor){
    if(actorid == 1){
        this->lifeState = 0;

    }
}