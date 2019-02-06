//
// Created by MORTEN on 07.12.2016.
//

#include "Boss_door.h"
Boss_door::Boss_door(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){

    height = 32*5;
    width = 32;
    dir =0;
    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    prevlocation.x = x;
    prevlocation.y = y;
    immunity = 0;
    lifeState =10;
    actorid = 1;

    floor = conf.windowHeight-32-height;
    speed = 1;

    door.setFillColor(sf::Color::Transparent);
    door.setSize(sf::Vector2f(width, height));
    texture.loadFromFile("Resources/DoorSpriteSheet.png");
    playerImage.setTexture(texture);
    playerImage.setScale(6.4 ,5 );

}
void Boss_door::move(){



}
void Boss_door::draw(){
    animation.Dooranimation(this);
    door.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x,y));
    if(actorid != 5){
    vindu.draw(door);}
    else{
        vindu.draw(playerImage);
    }
}
void  Boss_door::jump(){

}

void Boss_door::interaction( std::vector<Actor_Class*> actor_array) {


    if (actorid== 5) {
        lifeState = 0;
        door.setFillColor(sf::Color::Blue);
    }
    for (int i = 0; i < actor_array.size(); ++i) {

        if (actor_array[i]->immunity == 5) {

            lifeState = 1;
            actorid = 5;
        }
        if (actorid == 5){
        if (actor_array[i]->actorid == 92) {
            actor_array[i]->lifeState = 0;
        }
    }


        }

    }

void Boss_door::interaction_effect(Actor_Class* actor){

    if(actorid == 92){actor->lifeState = 0;}
if(actor->actorid == this->actorid || actor->actorid == 3){

    return;
}
        actor->setX(actor->prevlocation.x);
        if(actor->dir ==0 ){
            actor->dir =1;
        } else{
            actor->dir =0;
        }

    }


void Boss_door::death() {
}
