//
// Created by kab95 on 11.11.2016.
//

#ifndef HM_PROJECT_SPIKE_TILE_H
#define HM_PROJECT_SPIKE_TILE_H
#include "Action_Tile.h"



class Spike_Tile : public Action_Tile {

public:
    Spike_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw);
    void impact(Actor_Class* actor);
//    void levelswich(Actor_Class *actor,Collision* col){};
    int leeway = 14; // determines how much leeway is given towards the actor from above before death is triggered;
};


#endif //HM_PROJECT_SPIKE_TILE_H
