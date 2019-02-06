//
// Created by kab95 on 21.11.2016.
//

#ifndef HM_PROJECT_SEMISOLID_TILE_H
#define HM_PROJECT_SEMISOLID_TILE_H
#include "Solid_Tile.h"


class Semisolid_Tile : public Super_Tile{
public:
    Semisolid_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw);
    void impact(Actor_Class* actor){return;}
};


#endif //HM_PROJECT_SEMISOLID_TILE_H
