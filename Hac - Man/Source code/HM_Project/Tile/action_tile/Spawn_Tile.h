//
// Created by kab95 on 11.11.2016.
//

#ifndef HM_PROJECT_SPAWN_TILE_H
#define HM_PROJECT_SPAWN_TILE_H
#include "../Super_Tile.h"


class Spawn_Tile : public Super_Tile{

public:
    int spawningEnemyType;
    bool spawnTest;
    Spawn_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw, int spawnActor);
    void impact(Actor_Class* actor);
    int spawn();

};


#endif //HM_PROJECT_SPAWN_TILE_H
