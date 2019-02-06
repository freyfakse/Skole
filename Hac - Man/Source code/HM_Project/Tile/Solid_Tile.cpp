//
// Created by kab95 on 01.11.2016.
//

#include <iostream>
#include "Solid_Tile.h"

Solid_Tile::Solid_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw){
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    solid = true;
}
void Solid_Tile::impact(Actor_Class* actor) {
    if (actor->speed > actor->minSpeed){
        actor->speed = actor->speed-1;

        if(actor->speed <= actor->minSpeed+1){ //forhindrer at goomba glitcher gjennom gulvet
            actor->speed = actor->minSpeed;
        }
    }
}