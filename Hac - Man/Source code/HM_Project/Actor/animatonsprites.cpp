//
// Created by MORTEN on 10.12.2016.
//

#include "animatonsprites.h"
#include "iostream"


void animatonsprites::animationHero(Actor_Class *actor) {



        if (actor->dir == 0) //hvis man går mot høyre
        {
            actor->rectSourceSprite.top = 0;
            actor->rectSourceSprite.width=26;
            actor->rectSourceSprite.height=26;


            if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
                //   std::cout<<rectSourceSprite.left<<std::endl;
                if (actor->imortal <= 0) {

                    if (actor->action_taken == -1) {
                        if (actor->rectSourceSprite.left == 93) {

                            actor->rectSourceSprite.left = 120;

                        } else if (actor->rectSourceSprite.left == 120) {
                            actor->rectSourceSprite.left = 147;
                        } else {
                            actor->rectSourceSprite.left = 93;
                        }
                    } else {
                       // std::cout << rectSourceSprite.left << std::endl;
                        actor->rectSourceSprite.top = 40;
                        actor->rectSourceSprite.width = 30;
                        if (actor->rectSourceSprite.left == 40) {

                            actor->rectSourceSprite.left = 78;

                        } else if (actor->rectSourceSprite.left == 78) {
                            actor->rectSourceSprite.left = 110;
                        } else {
                            actor->rectSourceSprite.left = 40;
                        }

                    }

                    if (actor->standing_still == 0) {
                        actor->rectSourceSprite.left = 0;
                        if (actor->action_taken == 1) {
                            actor->rectSourceSprite.top = 37;
                            actor->rectSourceSprite.left = 3;
                            actor->rectSourceSprite.width = 30;
                        }

                    }
                    if (actor->falling == 0) {
                        actor->rectSourceSprite.left = 176;
                        actor->rectSourceSprite.width = 24;
                        actor->rectSourceSprite.height = 30;

                        if (actor->action_taken == 1) {
                            actor->rectSourceSprite.left = 143;
                            actor->rectSourceSprite.width = 30;
                            actor->rectSourceSprite.top = 30;
                        }

                    }

                }else{
                    actor->rectSourceSprite.top=72;
                    if(actor->rectSourceSprite.left==5){
                        actor->rectSourceSprite.left=30;
                    }else{
                        actor->rectSourceSprite.left=5;

                    }

                }


                    actor->playerImage.setTexture(actor->texture, true);
                    actor->playerImage.setTextureRect(actor->rectSourceSprite);
                    actor->Playerclock.restart();

                }

        }
        if (actor->dir == 1) //hvis man går mot venstre
        {

            actor->rectSourceSprite.top = 107;
            actor->rectSourceSprite.width=26;
            actor->rectSourceSprite.height=26;
            if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {

                if (actor->imortal <= 0) {
                //   std::cout<<rectSourceSprite.left<<std::endl;
                if (actor->action_taken == -1)
                {
                if (actor->rectSourceSprite.left == 30)
                {
                    actor->rectSourceSprite.left = 56;
                }
                else if (actor->rectSourceSprite.left == 56)
                {
                        actor->rectSourceSprite.left = 80;
                }
                 else
                {
                    actor->rectSourceSprite.left = 30;
                }
                }//run end
                else
                {
                    actor->rectSourceSprite.width=30;
                    actor->rectSourceSprite.top=145;
                    if (actor->rectSourceSprite.left == 57)
                    {

                        actor->rectSourceSprite.left = 98;
                    }
                      else if (actor->rectSourceSprite.left == 98)
                    {
                            actor->rectSourceSprite.left = 129;
                    }
                    else
                    {
                        actor->rectSourceSprite.left = 57;
                    }


                }

                if(actor->standing_still == 0){
                    actor->rectSourceSprite.width=23;
                    actor->rectSourceSprite.height=30;

                    actor->rectSourceSprite.left=177;
                    if(actor->action_taken==1){
                        actor->rectSourceSprite.top=145;
                        actor->rectSourceSprite.left=165;
                        actor->rectSourceSprite.width=30;
                    }

                }
                if(actor->falling==0){
                    actor->rectSourceSprite.height=30;
                    actor->rectSourceSprite.width=30;
                    actor->rectSourceSprite.left =0;
                    if(actor->action_taken==1){
                        actor->rectSourceSprite.left =27 ;
                        actor->rectSourceSprite.top=140;
                     //   actor->rectSourceSprite.height=30;
                      //  actor->rectSourceSprite.width=30;
                    }
                }

                }else{
                    actor->rectSourceSprite.top=179;
                    if(actor->rectSourceSprite.left==145){
                        actor->rectSourceSprite.left=170;
                    }else{
                        actor->rectSourceSprite.left=145;

                    }

                }

                actor->playerImage.setTexture(actor->texture, true);
                actor->playerImage.setTextureRect(actor->rectSourceSprite);
                actor->Playerclock.restart();
            }
        }




    }



void animatonsprites::animationBullet(Actor_Class* actor) {
    if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
        //    if(actor->actorid == 1) {

        actor->playerImage.setOrigin(0,5);
        actor->rectSourceSprite.top = 212;
        actor->rectSourceSprite.width = 32;
        actor->rectSourceSprite.height = 8;
        if (actor->direction == 0) {


            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }

        if (actor->direction == 1) {


            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(180);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 3) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(90);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 2) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(270);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 7) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(45);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 6) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(135);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 4) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(225);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
        if (actor->direction == 5) {




            if (actor->rectSourceSprite.left == 40) {
                actor->rectSourceSprite.left = 75;
            } else {
                actor->rectSourceSprite.left = 40;
            }

            actor->playerImage.setRotation(315);
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }

    }
}



void animatonsprites::FlyingBoss(Actor_Class *actor)
{


    if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
        actor->rectSourceSprite.height = 63;
        actor->rectSourceSprite.width = 66;


            actor->rectSourceSprite.top = 0;

            if(actor->action_taken == 4)
            {
               actor->rectSourceSprite.top =66;
            }
            if(actor->imortal > 0)
            {
                actor->rectSourceSprite.top = 132;
            }

            if (actor->rectSourceSprite.left == 0) {
                actor->rectSourceSprite.left =72;
              //  std::cout<<actor->rectSourceSprite.left<<std::endl;
            } else if(actor->rectSourceSprite.left ==72){
                actor->rectSourceSprite.left = 148;
            } else{
                actor->rectSourceSprite.left = 0;
            }

            //std::cout<<actor->rectSourceSprite.top<<std::endl;
            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }

    }
void animatonsprites::Turretanimation(Actor_Class* actor){

actor->rectSourceSprite.width = 32;
    actor->rectSourceSprite.height = 32;
    if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
        if(actor->rectSourceSprite.left == 0){
            actor->rectSourceSprite.left =48;
        } else if(actor->rectSourceSprite.left == 48){
            actor->rectSourceSprite.left = 96;
        } else if(actor->rectSourceSprite.left == 96) {
           actor->rectSourceSprite.left = 144;
        } else{
            actor->rectSourceSprite.left = 0;
        }

        actor->playerImage.setTexture(actor->texture, true);
        actor->playerImage.setTextureRect(actor->rectSourceSprite);
        actor->Playerclock.restart();
    }



}



  void animatonsprites::Dooranimation(Actor_Class *actor) {


      if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
          actor->rectSourceSprite.height = 32;
          actor->rectSourceSprite.width = 5;


          actor->rectSourceSprite.top = 0;



          if (actor->rectSourceSprite.left == 0) {
              actor->rectSourceSprite.left =10;
          } else if(actor->rectSourceSprite.left ==10){
              actor->rectSourceSprite.left = 20;
          } else if(actor->rectSourceSprite.left ==20){
              actor->rectSourceSprite.left = 30;
          }else if(actor->rectSourceSprite.left ==30){
              actor->rectSourceSprite.left = 40;
          }else{
              actor->rectSourceSprite.left = 0;
          }


          actor->playerImage.setTexture(actor->texture, true);
          actor->playerImage.setTextureRect(actor->rectSourceSprite);
          actor->Playerclock.restart();
      }




  }

void animatonsprites::Bossanimtion(Actor_Class *actor) {



    if (actor->dir == 1) //hvis man går mot høyre
    {
        actor->rectSourceSprite.top = 0;
        actor->rectSourceSprite.width=25;
        actor->rectSourceSprite.height=30;


        if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {
            //   std::cout<<rectSourceSprite.left<<std::endl;
            if (actor->imortal <= 0) {

                if (actor->action_taken == -1) {
                    if (actor->rectSourceSprite.left == 65) {

                        actor->rectSourceSprite.left = 95;

                    } else if (actor->rectSourceSprite.left == 95) {
                        actor->rectSourceSprite.left = 117;
                    } else {
                        actor->rectSourceSprite.left = 65;
                    }
                } else {
                   // std::cout << rectSourceSprite.left << std::endl;
                    actor->rectSourceSprite.top = 34;
                    actor->rectSourceSprite.width = 30;


                        actor->rectSourceSprite.left = 112;

                    }



                if (actor->standing_still == 0) {
                    actor->rectSourceSprite.left = 0;
                    if (actor->action_taken == 1) {
                        actor->rectSourceSprite.top = 0;
                        actor->rectSourceSprite.left = 4;
                        actor->rectSourceSprite.width = 30;
                    }

                }
                if (actor->falling == 0) {
                    actor->rectSourceSprite.left = 146;
                    actor->rectSourceSprite.width = 26;
                    actor->rectSourceSprite.height = 35;


                }

            }else{
                actor->rectSourceSprite.top=35;
                if(actor->rectSourceSprite.left==7){
                    actor->rectSourceSprite.left=35;
                }else{
                    actor->rectSourceSprite.left=7;

                }

            }


            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();

        }

    }
    if (actor->dir == 0) //hvis man går mot venstre
    {

        actor->rectSourceSprite.top = 84;
        actor->rectSourceSprite.width=25;
        actor->rectSourceSprite.height=30;
        if (actor->Playerclock.getElapsedTime().asSeconds() > 0.07f) {

            if (actor->imortal <= 0) {
                //   std::cout<<rectSourceSprite.left<<std::endl;
                if (actor->action_taken == -1)
                {
                    actor->rectSourceSprite.top = 86;
                    if (actor->rectSourceSprite.left == 35)
                    {
                        actor->rectSourceSprite.left = 60;
                    }
                    else if (actor->rectSourceSprite.left == 60)
                    {
                        actor->rectSourceSprite.left = 82;
                    }
                    else
                    {
                        actor->rectSourceSprite.left = 35;
                    }
                }//run end
                else
                {
                    actor->rectSourceSprite.width=30;
                    actor->rectSourceSprite.top=145;
                   actor->rectSourceSprite.left = 31;
                    actor->rectSourceSprite.top = 117;


                }

                if(actor->standing_still == 0){
                    actor->rectSourceSprite.width=23;
                    actor->rectSourceSprite.height=30;

                    actor->rectSourceSprite.left=177;
                    if(actor->action_taken==1){
                        actor->rectSourceSprite.top=145;
                        actor->rectSourceSprite.left=165;
                        actor->rectSourceSprite.width=30;
                    }

                }
                if(actor->falling==0){
                    actor->rectSourceSprite.top = 84;
                    actor->rectSourceSprite.height=35;
                    actor->rectSourceSprite.width=30;
                    actor->rectSourceSprite.left =0;


                }

            }else{
                actor->rectSourceSprite.top=119;
                if(actor->rectSourceSprite.left==115){
                    actor->rectSourceSprite.left=143;
                }else{
                    actor->rectSourceSprite.left=115;

                }

            }

            actor->playerImage.setTexture(actor->texture, true);
            actor->playerImage.setTextureRect(actor->rectSourceSprite);
            actor->Playerclock.restart();
        }
    }




}





