//
// Created by kab95 on 01.11.2016.
//

#ifndef HM_PROJECT_SOLID_TILE_H
#define HM_PROJECT_SOLID_TILE_H
#include "Super_Tile.h"


class Solid_Tile : public Super_Tile{

public:
    Solid_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw);
    void impact(Actor_Class* actor);

};


#endif //HM_PROJECT_SOLID_TILE_H
