//
// Created by MORTEN on 18.11.2016.
//


#include "boss_fight_1.h"

boss_fight_1::boss_fight_1(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){


    height = 130;
    width = 130;
    dir =0;
    spriteHeight = 2.8;
    spriteWidth = 2.5;

    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;

    health = 30;
    immunity = 5;
    floor = conf.windowHeight-32-height;



    boss.setFillColor(sf::Color::Red);
    boss.setSize(sf::Vector2f(width, height));


    ///ensures that the hero texture has been loaded
    if(!spriteTexture.loadFromFile("Resources/Boss.png", sf::IntRect(0,0,56,56)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }

    playerImage.setTexture(spriteTexture);


    playerImage.setPosition(x, y);
    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));

   // sound.openFromFile("hit_3.wav");
}
void boss_fight_1::move(){

imortal--;
    y += speed;

    speed = 5;
    prevlocation.x=x;
    prevlocation.y=y;



    if(x>0 && dir == 0){
        x -= speed;}
    else {dir=1;}
    if(dir == 1){
        x +=speed;
    }
    col.tileCollision(this);

    if (falling==0)
    {
        //   gravity=5;
        y += gravity;
    } else{
        y= floor;

    }



}


void boss_fight_1::jump(){
    // if som random lokking number
    //jump  start counting over again
    if(boss_jump<= 0){
        gravity=-15;
        boss_jump = 50;
    }
    else{
        boss_jump--;
        y +=gravity;
        if(gravity<=10) {
            gravity++;
        }
    }


}

void boss_fight_1::action() {
    if(boss_shoot<= 0){
        action_taken = 4;
        boss_shoot = 40;
    }
    else{
        action_taken = -1;
        boss_shoot--;
    }
}


void boss_fight_1::death() {




    if(imortal < 0) {
        imortal = 15;
        health += -1;

//        sound.play();
        if(health<=0){
            lifeState=0;
        }
    }
}
void boss_fight_1::draw() {
    boss.setPosition(sf::Vector2f(x, y));
    playerImage.setPosition(sf::Vector2f(x,y));

    vindu.draw(playerImage);
}