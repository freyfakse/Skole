//
// Created by kab95 on 01.11.2016.
//

#ifndef HM_PROJECT_SUPER_TILE_H
#define HM_PROJECT_SUPER_TILE_H
#include <SFML/Graphics.hpp>
#include "../Actor/actor_class.h"



class Super_Tile {
public:
    int id = 0;
    sf::Vector2f nw;
    sf::Vector2f ne;
    sf::Vector2f sw;
    sf::Vector2f se;

    bool solid = true;
    int direction;

    virtual void impact(Actor_Class* actor);

};


#endif //HM_PROJECT_SUPER_TILE_H
