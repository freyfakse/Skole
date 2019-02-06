//
// Created by Jonas on 10.12.2016.
//

#include "turret_S.h"

turret_S::turret_S(sf::RenderWindow& window, Collision col,int xInn ,int yInn) : vindu(window), col(col){

    height = 32;
    width = 32;
    //dir =0;

    startX = xInn;
    startY = yInn;
    x = startX;
    y = startY;
    immunity = 1;
    floor = conf.windowHeight-32-height;
    speed = 1;

    turretsS.setFillColor(sf::Color::Green);
    turretsS.setSize(sf::Vector2f(width, height));
    texture.loadFromFile("Resources/TurretDown.png");
    rectSourceSprite.width =32;
    rectSourceSprite.height = 32;
    playerImage.setTexture(texture,true);
    playerImage.setTextureRect(rectSourceSprite);
}

void turret_S::move(){}

void turret_S::draw(){
    turretsS.setPosition(sf::Vector2f(x,y));
    playerImage.setPosition(sf::Vector2f(x,y));
    animation.Turretanimation(this);
    vindu.draw(playerImage);
}

void turret_S::jump() {}

void turret_S::death() {}

void turret_S::interaction( std::vector<Actor_Class*> actor_array){

    if(actor_array[0]->getX() < this->getX()+conf.windowWidth/2)//skyter ikke når helt står til høyre for tårn
    {
        if(actor_array[0]->getX() > this->getX()-conf.windowWidth/2)//skyter ikke når helt står til venstre for tårn
        {
            if(actor_array[0]->getY() < this->getY()+conf.windowHeight)//skyter ikke når helt står under for tårn
            {
                if(actor_array[0]->getY() > this->getY()-conf.windowHeight)//skyter ikke når helt står over for tårn
                {
                    if(boss_shoot<= 0){
                        action_taken = 3;
                        boss_shoot = 50;
                    }
                    else{
                        action_taken = -1;
                        boss_shoot--;
                    }
                }
            }
        }
    }
}