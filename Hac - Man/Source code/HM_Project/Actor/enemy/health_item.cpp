//
// Created by MORTEN on 09.12.2016.
//

#include "health_item.h"


health_item::health_item(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){

    height = 30;
    width = 30;
    dir =0;

    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    immunity = 0;
    floor = conf.windowHeight-32-height;
    speed = 1;

    texture.loadFromFile("Resources/MedkitV2.png");
    playerImage.setTexture(texture);

    heart.setFillColor(sf::Color::Red);
    heart.setSize(sf::Vector2f(width, height));

}
void health_item::move(){


}
void health_item::draw(){
    heart.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x,y));
    vindu.draw(playerImage);
}

void health_item::interaction_effect(Actor_Class *actor) {
    if(lifeState == 0){
        return;
    }
    if(actor->actorid ==1){
        actor->lifeState++;
        this->lifeState =0;
    }


}
void health_item::jump(){

}
void health_item::death() {
    std::cout << "die ";
    lifeState = 0;
}