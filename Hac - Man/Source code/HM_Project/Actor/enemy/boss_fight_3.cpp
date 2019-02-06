//
// Created by MORTEN on 09.12.2016.
//

#include "boss_fight_3.h"


boss_fight_3::boss_fight_3(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){

    height = 70;
    width = 70;
    dir =0;
    tempdir = dir;
    spriteHeight = 2;
    spriteWidth = 2;
    standing_still = -1;

    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    health = 30;
    immunity = 5;
    floor = conf.windowHeight-32-height;



    boss.setFillColor(sf::Color::Red);
    boss.setSize(sf::Vector2f(width, height));

    texture.loadFromFile("Resources/Fiende1SpriteSheet.png");
    playerImage.setTexture(texture);
    playerImage.setTexture(texture, true);
    rectSourceSprite = sf::IntRect(0,0,30,30);
   playerImage.setTextureRect(rectSourceSprite);



    playerImage.setPosition(x, y);
    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));

 //   sound.openFromFile("hit_3.wav");
}
void boss_fight_3::move(){
imortal--;

    prevlocation.x=x;
    prevlocation.y=y;

    if(dir != tempdir){
        wallhitcounter++;
        tempdir =dir;
    }
if(movment == 0) {
    random--;
    random2--;
    random3--;
}

    if(random < 0){
        movment = 1;
        random = 80;
    }
    if(random2 < 0){
        movment =2;
        random2 = 100;
    }
    if(random3 < 0){
        movment = 3;
        random3 = 110;
    }

    col.tileCollision(this);
    moveswicher(&movment);



    if(x>0 && dir == 0){
        x -= speed;}
    else {dir=1;}
    if(dir == 1){
        x +=speed;
    }


    if (falling==0)
    {
        //   gravity=5;
        y += gravity;
    } else{
        y= floor;

    }

    y +=gravity;

}
void boss_fight_3::moveswicher(int* move) {

    if(*move == 1 )//falling = 1 betyr at den står på bakken
    {
        speed =20;
        bullet =-1;
        boss_jump = 5;//setter den konstant over 0 gjør at bossen ikke hopper

        if(wallhitcounter >= 3)
        {
            speed = 5;
            wallhitcounter = 0;
            *move =0;


        }
    }//if end
    if(*move ==2)
    {
        boss_jump+=-1;
        boss_shoot+=2;
        bullet = 3;
        if(wallhitcounter >= 2)
        {
           boss_jump =50;
            wallhitcounter = 0;
            *move =0;
        }

    }//else if end

    if(*move == 3  )
    {
        speed = 1;
        bullet = 5;
        boss_jump = 5;//setter den konstant over 0 gjør at bossen ikke hopper

        if(wallhitcounter >= 3)
        {

            wallhitcounter =0;
            *move =0;
        }
    }//else if

        if(*move == 0)
        {
        speed = 5;
        bullet = 4;
            wallhitcounter =0;

    }
    minSpeed =speed;
    maxSpeed = speed;
}


void boss_fight_3::jump(){
    // if som random lokking number

    //jump  start counting over again
    if(boss_jump<= 0){

        gravity=-15;
        boss_jump = 100;
    }
    else{
        boss_jump--;
       // col.tileCollision(this);


        if(gravity<=10) {
            gravity++;
        }
    }


}

void boss_fight_3::action() {
    if(boss_shoot<= 0){

        action_taken = bullet;
        boss_shoot = 40;
    }
    else{
        action_taken = -1;
        boss_shoot--;

    }
}


void boss_fight_3::death() {

    if(imortal < 0) {
        imortal = 15;
        health += -1;
        if(health<=0){
            lifeState=0;
        }
    }
}
void boss_fight_3::draw() {
    boss.setPosition(sf::Vector2f(x, y));
    playerImage.setPosition(sf::Vector2f(x,y));
    animaton.Bossanimtion(this);
    vindu.draw(playerImage);
}