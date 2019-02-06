//
// Created by MORTEN on 16.11.2016.
//

#include "Flying_enemy.h"

Flying_enemy::Flying_enemy(sf::RenderWindow &window, Collision col, int xInn, int yInn, Config& conf) : vindu(window), col(col), conf(conf){

    height = 60;
    width = 30;
    dir =1;
    spriteHeight =2;
    spriteWidth = 2;
    lifeState =1;

    x = xInn;
    y = yInn;
    prevlocation.x =x;
    prevlocation.y =y;

    immunity = 1;
   // floor = conf.windowHeight-32-height;

    speed = 5;

    corrupt_file.setFillColor(sf::Color::Blue);
    corrupt_file.setSize(sf::Vector2f(width, height));


    ///ensures that the hero texture has been loaded
    if(!spriteTexture.loadFromFile("Resources/fiende2.png", sf::IntRect(0,0,320,240)))
    {
        std::cout << "error in hero Texture loading"  << std::endl;
    }

    playerImage.setTexture(spriteTexture);
    playerImage.setScale(sf::Vector2f(spriteWidth, spriteHeight));
/*
    std::cout << "viruslyd1" << std::endl;
    sound.openFromFile("hit_3.wav");
    std::cout << "viruslyd2" << std::endl;
    */
}

void Flying_enemy::move() {
    imortal--;
    roof = false;
    col.tileCollision(this);

    //prevlocation.x =x;

   /* movment--;
    if( movment < 0){
        if(speed==5){
            speed=-5;
        } else{
            speed=5;
        }
        movment =200;
    }*/


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
    }
   if(y >= conf.getLevelHeight()){//når den treffer gulvet skal den opp igjen
       speed = -5;
    }
    y+=speed;
  //  x = prevlocation.x;
}



void Flying_enemy::death() {
/*
    std::cout << "viruslyd3" << std::endl;
    sound.play();
    std::cout << "viruslyd4" << std::endl;
    Brukes til lyd men forusaker lagg
*/

    if(imortal < 0) {
        imortal = 1;
        lifeState--;
    }
}

void Flying_enemy::draw() {
    corrupt_file.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x,y));
    vindu.draw(playerImage);
}
void Flying_enemy::jump() {

}