//
// Created by MORTEN on 31.10.2016.
//

#ifndef HM_PROJECT_INTERACTING_H
#define HM_PROJECT_INTERACTING_H

#include "../Actor/actor_class.h"
#include "../Tile/Super_Tile.h"

class interacting {
public:
    interacting();
    void setUp(Actor_Class* actor_a, Actor_Class* actor_b ,float tile_x,float tile_with,float tile_y, float tile_height,bool tile);
    void death(Actor_Class* actor_a, Actor_Class* actor_b);
    void floor(Actor_Class* actor_a,float tile_x,float tile_with, float tile_y, float actor_y);
};


#endif //HM_PROJECT_INTERACTING_H
