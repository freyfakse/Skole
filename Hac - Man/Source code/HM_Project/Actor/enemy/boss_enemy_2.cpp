//
// Created by MORTEN on 08.12.2016.
//

#include "boss_enemy_2.h"


boss_enemy_2::boss_enemy_2(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){


    height = 50;
    width = 50;
    dir =0;
    spriteHeight = 1.5;
    spriteWidth = 1.5;

    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    prevlocation.x =x;
    prevlocation.y =y;
    health = 20;
    immunity = 5;
    floor = conf.windowHeight-32-height;



    boss.setFillColor(sf::Color::Red);
    boss.setSize(sf::Vector2f(width, height));

    texture.loadFromFile("Resources/FlyingBossEnemy.png");

    ///ensures that the hero texture has been loaded
    if(!spriteTexture.loadFromFile("Resources/FlyingBossEnemy.png", sf::IntRect(0,0,57,63)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }

    playerImage.setTexture(spriteTexture);


    playerImage.setPosition(x, y);
    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));

   // sound.openFromFile("hit_3.wav");
}
void boss_enemy_2::move(){
    imortal--;
    roof = false;
    col.tileCollision(this);
    x= prevlocation.x;

    movment--;
    if( movment < 0){
        if(speed==5){
            speed=-5;
        } else{
            speed=5;
        }
        movment =200;
    }


    if(falling== 1)
    {
        speed = -5;

    }
    else if( roof )
    {// når den treffe bunnen av en tile skal den opp
        speed = 5;

    }

    if(y <= 0){ //når den treffer taket skal den gå ned igjen
        speed=5;
        dir = 3;
    }
    if(y >= conf.windowHeight){//når den treffer gulvet skal den opp igjen
        speed = -5;
        dir = 2;
    }
    y+=speed;
    x = prevlocation.x;
}


void boss_enemy_2::jump(){
}

void boss_enemy_2::action() {
    if(boss_shoot<= 0){
        action_taken = 4;
        boss_shoot = 30;
    }
    else{
        action_taken = -1;
        boss_shoot--;
    }
}


void boss_enemy_2::death() {

    if(imortal < 0) {
        imortal = 15;
        health += -1;
        if(health<=0){
            lifeState=0;
        }
    }


}
void boss_enemy_2::draw() {
    boss.setPosition(sf::Vector2f(x, y));
    playerImage.setPosition(sf::Vector2f(x, y));
    animation.FlyingBoss(this);
    vindu.draw(playerImage);
}

