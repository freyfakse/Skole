//
// Created by MORTEN on 20.10.2016.
//

#include "Shooting_Mechanic.h"

ShotingMechanic::ShotingMechanic(sf::RenderWindow &window, collision* col): vindu(window), kollisjon(col)
{

}

void ShotingMechanic::heroShot(Hero helt) {
//lagrer retningen
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { dir = 0; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { dir = 1; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { dir = 2; }

//lager en kule i en vector
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        projectile* bullet = new projectile(helt);
        bullet->direction = dir;
        bullet->actorid = hero.actorid;

        bulletVector.push_back(*bullet);
    }

    //flytter alle kulene

    for (int i = 0; i < bulletVector.size(); ++i) {

    if (bulletVector[i].direction == 0) { bulletVector[i].setX( bulletVector[i].getX()+ 10); }
    if (bulletVector[i].direction == 1) {bulletVector[i].setX( bulletVector[i].getX() -10); }
    if (bulletVector[i].direction == 2) {bulletVector[i].setY( bulletVector[i].getY() -10); }
        if(bulletVector[i].getX() <= 0 || bulletVector[i].getX() >=  configer.windowWidth){bulletVector.erase(bulletVector.begin()+i);}
        if(bulletVector[i].getY() <= 0 || bulletVector[i].getY() >= configer.windowWidth){bulletVector.erase(bulletVector.begin()+i);}
    }//for end//*/
    kollisjon->import_projectiles(bulletVector);
}//hero shot end

void ShotingMechanic::draw()
{
    for (int i = 0; i <bulletVector.size() ; ++i) {
    bulletVector[i].bullet.setPosition(bulletVector[i].getX(),bulletVector[i].getY());
    vindu.draw(bulletVector[i].bullet);}
}