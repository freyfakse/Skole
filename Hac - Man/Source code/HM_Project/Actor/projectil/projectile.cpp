//
// Created by MORTEN on 20.10.2016.
//

#include"projectile.h"


Projectile::Projectile(Actor_Class helt) {

    rectSourceSprite = sf::IntRect(0, 0, 26, 26);
    ///ensures that the hero texture has been loaded
    if (helt.actorid == 1) {
        texture.loadFromFile("Resources/HMPlayerV2.png");
    }

    else{
        texture.loadFromFile("Resources/GoombaSprites2.png");
        }


  //  playerImage.setTexture(spriteTexture);
    playerImage.setScale(2,2);


    //playerImage.setPosition(x, y);

    x = helt.getX() + (helt.width/2);
    y = helt.getY() + (helt.height/2);
    height =10;
    width =10;
    speed = 10;
    immunity = helt.immunity;
    bullet.setRadius(10);
    bullet.setPosition(x,y);
    bullet.setFillColor(sf::Color::Blue);
}
