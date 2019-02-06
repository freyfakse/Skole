//
// Created by MORTEN on 31.10.2016.
//

#include "interacting.h"


interacting::interacting(){}


void interacting::setUp(Actor_Class* actor_a, Actor_Class *actor_b,float tile_x,float tile_with, float tile_y, float tile_height,bool tile) {
    if((tile)  ) {

        death(actor_a, actor_b);
    }
    else if (actor_a->getY()!= tile_y){
    floor(actor_a ,tile_x,tile_with, tile_y, tile_height);}
}

void interacting::death( Actor_Class* actor_a,Actor_Class* actor_b) {

    if (!(actor_a->immunity == actor_b->immunity)) //tester for immunitet, kjører ikke .death() om de er like
    {
        actor_a->death();
    }
    if (!(actor_b->immunity == actor_a->immunity)) //tester for immunitet, kjører ikke .death() om de er like
    {
        actor_b->death();
    }
    actor_a->interaction_effect(actor_b);
    actor_b->interaction_effect(actor_a);

}

void interacting::floor(Actor_Class *actor_a,float tile_x,float tile_with,float tile_y, float tile_height) {


   if(actor_a->getY()+actor_a->height >= tile_y+tile_height)
    {


        actor_a->roof= true;

    if (tile_x >= actor_a->getX())
    {
        actor_a->setX(actor_a->prevlocation.x );


        actor_a->dir=0;


    }
   else if (tile_x + tile_with >= actor_a->getX())
    {
        actor_a->setX(actor_a->prevlocation.x);


        actor_a->dir=1;

    }

        if ( tile_x + tile_with <= actor_a->getX() ||actor_a->getX()+actor_a->width <= tile_x){
            return;
        } else{
            actor_a->gravity =8;
        }



}


else{

        actor_a->falling = 1;
        actor_a->gravity= 1;
        actor_a->floor = (int) tile_y - actor_a->height;

    }
}