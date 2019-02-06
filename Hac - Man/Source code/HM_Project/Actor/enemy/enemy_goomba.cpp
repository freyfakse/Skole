//
// Created by kab95 on 20.10.2016.
//

#include "enemy_goomba.h"



Enemy_Goomba::Enemy_Goomba(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){

    height = 50;
    width = 33;
    dir =0;
    lifeState =1;
   // spriteHeight = 1.5;

    standing_still =1;
    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    prevlocation.x =x;
    prevlocation.y =y;
    immunity = 1;
    floor = conf.windowHeight-32-height;
    speed = 1;
    rectSourceSprite = sf::IntRect(0,0,26,26);
    goomba.setFillColor(sf::Color::Yellow);
    goomba.setSize(sf::Vector2f(width, height));

    if(!spriteTexture.loadFromFile("Resources/GoombaSprites2.png", sf::IntRect(0,0,25,25)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }
    texture.loadFromFile("Resources/GoombaSprites2.png");
    playerImage.setTexture(spriteTexture);
    playerImage.setPosition(x, y);

    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));
/*
    std::cout << "goombalyd1" << std::endl;
    sound.openFromFile("hit_3.wav");
    std::cout << "goombalyd2" << std::endl;
    */
}
void Enemy_Goomba::move(){
    imortal--;
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
        gravity++;
        y += gravity;
    } else{
        y= floor;
        gravity= 0;
    }


    if(dir==0)dir=1;else{dir=0;}//swicher om på dir
    animation.animationHero(this);
    if(dir==0)dir=1;else{dir=0;}//swicher om på dir



}
void Enemy_Goomba::draw(){

    goomba.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x,y-10));

    vindu.draw(playerImage);
}
void Enemy_Goomba::jump(){}

void Enemy_Goomba::death() {
   /* std::cout << "goombalyd3" << std::endl;
    /*sound.play();
    std::cout << "goombalyd4" << std::endl;*/
    if(imortal < 0) {
        imortal = 3;
       lifeState--;
        }
    }

