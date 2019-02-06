//
// Created by MORTEN on 20.10.2016.
//

#ifndef HM_PROJECT_SHOTINGMECHANIC_H
#define HM_PROJECT_SHOTINGMECHANIC_H


#include "projectile.h"
#include "../../config.h"
#include "../Hero.h"
#include "vector"
#include "../../Fysik/collision.h"
#include "../animatonsprites.h"



class Shooting_Mechanic :public Super_Class {
protected:

    Config configer;
    int dir = 1;//shooting mecanik arver fra super_class så den har sin egen instanse av direction
    bool keyPressed = false; // brukes for å hindre at spilleren bare kan holde inne kanppen
    std::vector<Projectile*> bulletVector;// arrayet som alle prosjectilene rer lagret i
    sf::RenderWindow& vindu;
    Sound sound; // brukes til lyd når man skyter
    animatonsprites animasjon;

public:

    /// konstroktoren til enemy shoot
    /// \param window
    /// \param col
    /// \param conf
    /// \return
    Shooting_Mechanic(sf::RenderWindow& window, Collision* col, Config conf);

    /// denne functionen tar seg av opptegningen av prosjectilene
    void draw();
    /// en function som lager heltens kuler hvis man trykker på skyte knappen
    /// \param helt
    /// \param kameraPos
    void heroShot(Actor_Class* helt, int kameraPos);
    /// en function som lager findenes kuler når de har enemyshot satt til 0-5
    /// \param actor_array
    /// \param kameraPos
    void enemyshot(std::vector<Actor_Class*> actor_array,int kameraPos);
    /// brukes for å slette kuler
    /// \param projIndex
    void eraseProjectile(int projIndex);

    Collision* kollisjon;// brukes for å impotere arrayene fra shooting_mechanic over i collisjon til game state

    //skal lage et prosjektil som går fra hero


};


#endif //HM_PROJECT_SHOTINGMECHANIC_H
