//
// Created by kab95 on 11.11.2016.
//

#ifndef HM_PROJECT_SPEED_TILE_H
#define HM_PROJECT_SPEED_TILE_H
#include "Action_Tile.h"

class Speed_Tile : public Action_Tile{
public:
    Speed_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw);
    void impact(Actor_Class* actor);

    int speed = 3;
};


#endif //HM_PROJECT_SPEED_TILE_H
