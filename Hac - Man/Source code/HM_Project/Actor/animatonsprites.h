//
// Created by MORTEN on 10.12.2016.
//

#ifndef HM_PROJECT_ANIMATONSPRITES_H
#define HM_PROJECT_ANIMATONSPRITES_H



#include "../Actor/actor_class.h"
#include "../Actor/projectil/projectile.h"


class animatonsprites  : Actor_Class {
public:
    animatonsprites (){};
   void animationHero( Actor_Class*  actor);
    void animationBullet(Actor_Class* actor);
    void FlyingBoss(Actor_Class* actor);
    void Turretanimation(Actor_Class* actor);
    void Dooranimation(Actor_Class* actor);
    void Bossanimtion(Actor_Class* actor);


    void jump(){};
    void move(){}; //flytter karakteren
    void draw(){}; //tegner i importert vindu
    void death(){};


};


#endif //HM_PROJECT_ANIMATONSPRITES_H
