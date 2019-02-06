//
// Created by MORTEN on 06.12.2016.
//

#include "Finnish_tile.h"
#include "Tilemap.h"
#include "../States/game_state.h"
#include "../Fysik/collision.h"


Finnish_tile::Finnish_tile(sf::Vector2f *nw, sf::Vector2f *ne, sf::Vector2f *se, sf::Vector2f *sw) {
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    solid = false;
    id =1;

}



void Finnish_tile::impact(Actor_Class *actor) {

    if (actor->immunity == 0) {
        actor->lvl++;
        if(actor->lvl >6){
            actor->lvl=0;
        }

    }
}

