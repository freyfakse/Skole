//
// Created by kab95 on 11.11.2016.
//

#include "Spawn_Tile.h"


Spawn_Tile::Spawn_Tile(sf::Vector2f* nw, sf::Vector2f* ne, sf::Vector2f* se, sf::Vector2f* sw, int spawnActor){
    this->ne = *ne;
    this->nw = *nw;
    this->se = *se;
    this->sw = *sw;
    spawningEnemyType = spawnActor;
    spawnTest = false;

}
void Spawn_Tile::impact(Actor_Class* actor){

}
int Spawn_Tile::spawn() {
    spawnTest = true;
    return spawningEnemyType;
}
