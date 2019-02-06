//
// Created by kab95 on 11.11.2016.
//

#ifndef HM_PROJECT_ACTION_TILE_H
#define HM_PROJECT_ACTION_TILE_H
#include "../Super_Tile.h"


class Action_Tile : public Super_Tile{

public:
    virtual void impact(Actor_Class* actor);
//    virtual void levelswich(Actor_Class *actor,Collision col);
};


#endif //HM_PROJECT_ACTION_TILE_H
