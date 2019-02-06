//
// Created by kab95 on 18.10.2016.
//

#include "Hero.h"



Hero::Hero(sf::RenderWindow& window, Collision col, int xInn, int yInn) : vindu(window), col(col)  {  //vindu(window) legger referancen in i vindu variablen deklarert i header filen.

    Config conf;


    texture.loadFromFile("Resources/HMPlayerV2.png");
     rectSourceSprite = sf::IntRect(0,0,26,26);
/*
    sf::IntRect rectSourceSprite(0,0,450,240);
    sf::Sprite testsprite(texture, rectSourceSprite);
    testsprite.setScale(sf::Vector2f(2.3, 2.14));
*/
    sf::Clock clock;


    this->conf = conf;
    startX = xInn;
    startY = yInn;
    x = xInn;
    y = yInn;
    height = 25*spriteHeight;
    width = 21*spriteWidth;
    actorid = 1;
    immunity = 0;
    lifeState = 3;
    prevlocation.x=x;
    prevlocation.y=y + (height/2) ;
    speed = 5; //endrer hastigheten til karakteren
    maxSpeed = speed*4;
    minSpeed = speed;




    floor = conf.windowHeight-32-height; //mulig inkompatibel med dypere nivåer?

    ///ensures that the hero texture has been loaded
    if(!spriteTexture.loadFromFile("Resources/HMPlayerV2.png", sf::IntRect(0,0,23,26)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }

    playerImage.setTexture(spriteTexture);
    playerImage.setPosition(x, y);

    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));


}

void Hero::move() {

    animation.animationHero(this);


    imortal--;
    prevlocation.x = x;
    prevlocation.y = y;
standing_still =0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        dir = 0;
        x += speed;
standing_still =1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        dir = 1;
        x -= speed;
standing_still =1;
    }


    col.tileCollision(this);

    if (falling == 0) {
        //   if (floor >= y) {
        y += gravity;
    } else if (y >= floor /*&& dir == 1*/) {
        y = floor;
        //       gravity = 0;

    }

}

//funcsjonen vil la helten hoppe hvis han rører bakken og spilleren trykker på up og han går oppover til
void Hero::jump() {


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //sjekker om du har trykt på up
    {

        if (jumpVar == 0 && falling==1) {
            jumpVar = 1;
            gravity = -17;
            sounds.playJump();
            y += gravity;
        }
    }
        if (jumpVar == 1, /*&& y <= floor*/ gravity <= 20) {//har trukt på opp å er over bakken
            gravity++;

        }
        if (y == floor) {
            jumpVar = 0;

        }
    }


void Hero::death() {



    if(imortal < 0) {
        lifeState--;
        imortal = 15;

        sounds.playHit();
    }

    if(lifeState < 0) {
        lifeState = 0;
    }

}
void Hero::respawn(){

    x = startX;
    y = startY;
}


void Hero::draw(){
    playerImage.setPosition(x,y);
    //vindu.draw(helt);
    vindu. draw(playerImage);
}