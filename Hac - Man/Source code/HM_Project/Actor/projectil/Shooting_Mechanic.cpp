//
// Created by MORTEN on 20.10.2016.
//

#include "Shooting_Mechanic.h"

Shooting_Mechanic::Shooting_Mechanic(sf::RenderWindow &window, Collision* col, Config conf): vindu(window), kollisjon(col), configer(conf)
{
}

void Shooting_Mechanic::heroShot(Actor_Class* helt, int kameraPos) {

    bool addedActorSpeed = true;
    bool skyteBool = true;

    //lagrer kule rettning
    //lagrer retningen
    //scrapa ide at helten kunne skyte i 8 rettninger nå er det bare 4
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { dir = 4; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { dir = 5; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { dir = 6; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { dir = 7; }*/
    if      (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { dir = 0; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { dir = 1; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { dir = 2; }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { dir = 3; }
    else    {skyteBool = false;}

//lager en kule i en vector
    if (skyteBool == true && keyPressed == false && helt->action_taken != -2) {

        Projectile* bullet = new Projectile(*helt);
        bullet->direction = dir;
        bullet->actorid = 3;
        bulletVector.push_back(bullet);
        sound.shoot.setVolume(30);
        sound.playShoot();
        helt->action_taken =1;
        keyPressed = true;
    }
    if(skyteBool == false){
        keyPressed = false;
        helt->action_taken=-1;
    }

    //flytter alle kulene
    for (int i = 0; i < bulletVector.size(); ++i) {
        if (bulletVector[i]->direction == 4) { bulletVector[i]->setX( bulletVector[i]->getX()- bulletVector[i]->speed); bulletVector[i]->setY( bulletVector[i]->getY() -bulletVector[i]->speed); }
        if (bulletVector[i]->direction == 5) {bulletVector[i]->setX( bulletVector[i]->getX() +bulletVector[i]->speed); bulletVector[i]->setY( bulletVector[i]->getY() -bulletVector[i]->speed);}
        if (bulletVector[i]->direction == 6) {bulletVector[i]->setY( bulletVector[i]->getY() +bulletVector[i]->speed); bulletVector[i]->setX( bulletVector[i]->getX() -bulletVector[i]->speed);}
        if (bulletVector[i]->direction == 7) {bulletVector[i]->setY( bulletVector[i]->getY() +bulletVector[i]->speed); bulletVector[i]->setX( bulletVector[i]->getX() +bulletVector[i]->speed);}
        if (bulletVector[i]->direction == 0) { bulletVector[i]->setX( bulletVector[i]->getX()+ bulletVector[i]->speed); }
        if (bulletVector[i]->direction == 1) {bulletVector[i]->setX( bulletVector[i]->getX() -bulletVector[i]->speed); }
        if (bulletVector[i]->direction == 2) {bulletVector[i]->setY( bulletVector[i]->getY() -bulletVector[i]->speed); }
        if (bulletVector[i]->direction == 3) {bulletVector[i]->setY( bulletVector[i]->getY() +bulletVector[i]->speed); }
        if(bulletVector[i]->getX() <= kameraPos || bulletVector[i]->getX() >=  (configer.windowWidth+kameraPos)){eraseProjectile(i);}
        if(bulletVector[i]->getY() < 0 || bulletVector[i]->getY() > (configer.getLevelHeight()+configer.getLevelTileSize())){eraseProjectile(i);}
    }//for end//*/
    kollisjon->import_projectiles(bulletVector);
}//hero shot end



void Shooting_Mechanic::enemyshot(std::vector<Actor_Class*> actor_array,int kameraPos) {
    double relativeX = 0;//calculates distance between hero and shooter.
    double relativeY = 0;
    double leeway = 32;//default distance used to calculate each direction
    double magnitude = 1;//The distance leeway is increased by if larger than 5* leeway
    for (int i =1; i < actor_array.size(); i++) {

        if (actor_array[i]->action_taken == 4) {
            Projectile *bullet = new Projectile(*actor_array[i]);
            relativeX = (actor_array[0]->getX()+(actor_array[0]->width/2))- bullet->getX();
            relativeY = (actor_array[0]->getY()+(actor_array[0]->height/2)) - bullet->getY();

            if(relativeY < 0){ // calculates current hero posistion
                if(relativeY <= leeway*-5){leeway = magnitude*relativeY;}
                if(relativeX >= (leeway*-1)&& relativeX <= leeway){bullet->direction = 2;}
                else if (relativeX >=leeway && relativeX <= leeway*4) {bullet->direction = 5;}
                else if(relativeX <= leeway*-1 && relativeX >= leeway*-4){bullet->direction = 4;}
                else if(relativeX >= leeway*4){bullet->direction = 0;}
                else if(relativeX <= leeway*-4){bullet->direction = 1;}
            }
            else{
                if(relativeY >= leeway*5){leeway = magnitude*relativeY;}
                if(relativeX >= (leeway*-1)&& relativeX <= leeway){bullet->direction = 3;}
                else if (relativeX >=leeway && relativeX <= leeway*4) {bullet->direction = 7;}
                else if(relativeX <= leeway*-1 && relativeX >= leeway*-4){bullet->direction = 6;}
                else if(relativeX >= leeway*4){bullet->direction = 0;}
                else if(relativeX <= leeway*-4){bullet->direction = 1;}
            }

            bullet->immunity = actor_array[i]->immunity; //prevents shooting actor from being killed by own projectile
            bullet->actorid = 3; //identifies shooting actor
            bulletVector.push_back(bullet);
            sound.playShoot(); // plays sound effect
        }

        else if(actor_array[i]->action_taken == 5) {
            for (int j = 0; j < 8; ++j) {

                Projectile *bullet = new Projectile(*actor_array[i]);
                bullet->direction = j;
                bullet->immunity = actor_array[i]->immunity;
                bullet->actorid = 3;
                bulletVector.push_back(bullet);
            }

            sound.playShoot();


        }

        else if(actor_array[i]->action_taken == 3){

            Projectile *bullet = new Projectile(*actor_array[i]);
            bullet->direction =3;
            bullet->immunity = actor_array[i]->immunity;
            bullet->actorid = 3;
            bulletVector.push_back(bullet);


        }

        else if(actor_array[i]->action_taken == 2){

            Projectile *bullet = new Projectile(*actor_array[i]);
            bullet->direction =2;
            bullet->immunity = actor_array[i]->immunity;
            bullet->actorid = 3;
            bulletVector.push_back(bullet);


        }
        else if(actor_array[i]->action_taken == 1){

            Projectile *bullet = new Projectile(*actor_array[i]);
            bullet->direction =1;
            bullet->immunity = actor_array[i]->immunity;
            bullet->actorid = 3;
            bulletVector.push_back(bullet);

        }
        else if(actor_array[i]->action_taken == 0){

            Projectile *bullet = new Projectile(*actor_array[i]);
            bullet->direction =0;
            bullet->immunity = actor_array[i]->immunity;
            bullet->actorid = 3;
            bulletVector.push_back(bullet);


        }





    }
    for (int  i =0; i < bulletVector.size(); i++) {
        if (bulletVector[i]->getY() <= 0 || bulletVector[i]->getY() >= (configer.getLevelHeight()+configer.getLevelTileSize())) {
            eraseProjectile(i);
        }//if end

        kollisjon->import_projectiles(bulletVector);
    }//for end//*//
}// /enemyshot end
void Shooting_Mechanic::eraseProjectile(int projIndex) {
    bulletVector.erase(bulletVector.begin() + projIndex);
}

void Shooting_Mechanic::draw() {
    for (int i = 0; i <bulletVector.size() ; ++i) {
        if(bulletVector[i]->lifeState == 0){eraseProjectile(i);}
        bulletVector[i]->prevlocation.x =  bulletVector[i]->getX();
        bulletVector[i]->prevlocation.y =  bulletVector[i]->getY();
        animasjon.animationBullet(bulletVector[i]);
        bulletVector[i]->playerImage.setPosition(bulletVector[i]->getX(),bulletVector[i]->getY());
        bulletVector[i]->bullet.setPosition(bulletVector[i]->getX(),bulletVector[i]->getY());
        vindu.draw(bulletVector[i]->playerImage);}
}