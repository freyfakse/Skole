//
// Created by MORTEN on 20.10.2016.
//

#ifndef HM_PROJECT_PROJECTILE_H
#define HM_PROJECT_PROJECTILE_H



#include "../actor_class.h"



class Projectile : public Actor_Class {
public:
    /// lager en projectil på kordinatene til actor å prosjectilet går i retningen til actoren
    /// \param helt
    /// \return
    Projectile(Actor_Class helt);
    sf::CircleShape bullet;
};


#endif //HM_PROJECT_PROJECTILE_H
