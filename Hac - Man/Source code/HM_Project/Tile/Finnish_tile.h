//
// Created by MORTEN on 06.12.2016.
//

#ifndef HM_PROJECT_FINNISH_TILE_H
#define HM_PROJECT_FINNISH_TILE_H

#include "Super_Tile.h"
#include "Tilemap.h"
#include "../config.h"


class Finnish_tile : public Super_Tile{
public:

    Tilemap* map;
    Config conf;

//TODO må importe tilhørene kalsser å lage et object av den

    Finnish_tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw);
    void import(/*Config* import_conf,*/Tilemap* import_map);
    void impact(Actor_Class *actor);
 //   void levelswich(Actor_Class *actor,Collision* col);
};




#endif //HM_PROJECT_FINNISH_TILE_H
