//
// Created by kab95 on 21.11.2016.
//

#include "Semisolid_Tile.h"
Semisolid_Tile::Semisolid_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw){
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    solid = false;
}