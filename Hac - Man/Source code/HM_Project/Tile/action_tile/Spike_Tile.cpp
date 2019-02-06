//
// Created by kab95 on 11.11.2016.
//

#include <iostream>
#include "Spike_Tile.h"

Spike_Tile::Spike_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw){
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    solid = false;
}


void Spike_Tile::impact(Actor_Class* actor){
    if(this->direction == 0) {

        if ((actor->getY() + actor->height) > this->nw.y + leeway && (actor->getY() + actor->height) <= this->se.y || actor->getY() > this->nw.y +leeway && actor->getY() < this->se.y -leeway) {
            actor->lifeState = 0;
        }
    }
    if(this->direction == 1) {

        if ((actor->getY() + actor->height) >= this->nw.y && (actor->getY() + actor->height) < this->se.y - leeway || actor->getY() > this->nw.y +leeway && actor->getY() < this->se.y -leeway) {
            actor->lifeState = 0;
        }
    }
    if (this->direction == 2){
        if ((actor->getX() + actor->width) > this->nw.x  && (actor->getX() + actor->width) < this->se.x || actor->getX() > this->nw.x&& actor->getX() < this->se.x) {
            if(actor->getY() + actor->height > this->ne.y+leeway*2)
            actor->lifeState = 0;
        }
    }
    if (this->direction == 3){
        if ((actor->getX() + actor->width) > this->nw.x  && (actor->getX() + actor->width) < this->se.x || actor->getX() > this->nw.x&& actor->getX() < this->se.x) {
            if(actor->getY() + actor->height > this->ne.y+leeway*2)
                actor->lifeState = 0;
        }
    }
}