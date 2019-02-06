//
// Created by kab95 on 11.11.2016.
//

#include "Speed_Tile.h"

Speed_Tile::Speed_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw){
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    solid = true;
}
void Speed_Tile::impact(Actor_Class* actor){
    if (direction == 0) {
        actor->setX(actor->getX() + speed);
        if(actor->dir == 0){
            actor->speed=8;
        }

        actor->dir = 1;

    }
    else if(direction == 1){
        actor->setX(actor->getX() - speed);
        if(actor->dir ==1){
            actor->speed= 8;
        }

        actor->dir = 0;

    }
    if(actor->speed <= actor->maxSpeed) {
        actor->speed = actor->speed +1;

    }

}