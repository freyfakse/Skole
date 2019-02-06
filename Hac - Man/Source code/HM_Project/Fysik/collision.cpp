//
// Created by MORTEN on 24.10.2016.
//

#include "collision.h"



bool Collision::tileCollision (Actor_Class* actor){


    actiontileCollision(actor);

    actor->falling=0;
    temp_bool = false;

    for (int i=0 ; i < tile_array.size() ;i++){

           temp_bool = intersect(actor->getX()//x

                    , tile_array[i]->nw.x//x2
                    , actor->getY()//y
                    , tile_array[i]->nw.y//y2
                    , actor->height//height
                    , (int) tile_array[i]->se.y - (int) tile_array[i]->ne.y//height2
                    , actor->width //length
                    , (int)( tile_array[i]->ne.x -  tile_array[i]->nw.x)//length2
                    , actor, actor ,false
                    );//intersect end

            if (temp_bool== true){
                tile_array[i]->impact(actor);

                }

    }//for end
    return temp_bool;
}//tileCollision end
void Collision::actiontileCollision(Actor_Class* actor) { //funksjon som løser problem med ikke-solide actiontiles
    for(int i = 0; i < actiontile_array.size(); i++){
        if(actiontile_array[i]->solid == false){
            if (actor->getX()>actiontile_array[i]->nw.x && actor->getX() < actiontile_array[i]->ne.x || actor->getX()+actor->width>actiontile_array[i]->nw.x && actor->getX()+actor->width < actiontile_array[i]->ne.x){
                if(actor->getY()+actor->height >= actiontile_array[i]->nw.y && actor->getY()+actor->height <= actiontile_array[i]->sw.y || actor->getY()>= actiontile_array[i]->nw.y && actor->getY() <= actiontile_array[i]->sw.y){
                    actiontile_array[i]->impact(actor);
                }
            }
        }
    }
    return;
}//actiontileCollision end

void Collision::collisionDetection(std::vector<Actor_Class*> arry) {
    for (int i = 0; i <arry.size() ; ++i) {
        for (int j = 0; j <arry.size() ; ++j) {
            intersect(arry[i]->getX(),arry[j]->getX(),arry[i]->getY(),arry[j]->getY(),arry[i]->height,arry[j]->height,arry[i]->width,arry[j]->width, arry[i] ,arry[j],true);
        }//for 1 end
        if(arry[i]->getY() > conf.getLevelHeight()){

            arry[i]->lifeState = 0;

        }
    }//for 2 end

}//CollisionDetection end

void Collision::import_projectiles(std::vector<Projectile*> imported_projectile_array) {
    projectile_array = imported_projectile_array;
}//import

void Collision::import_map(std::vector<Super_Tile*>imported_tile_array, std::vector<Action_Tile*>imported_actiontile_array, std::vector<Spawn_Tile *> imported_spawn_array) {
    this->tile_array = imported_tile_array;
    this->actiontile_array = imported_actiontile_array;
    this->spawn_array = imported_spawn_array;
}
void Collision::projectile_hit(std::vector<Actor_Class *> actor_array) {
    bool temp_bool2;
    if(!projectile_array.size() == 0){
        for (int i = 0; i <actor_array.size() ; ++i) {
            for (int j = 0; j <projectile_array.size() ; ++j) {
                temp_bool2 = intersect(actor_array[i]->getX()
                        ,projectile_array[j]->getX()
                        ,actor_array[i]->getY()
                        ,projectile_array[j]->getY()
                        ,actor_array[i]->height
                        ,projectile_array[j]->height
                        ,actor_array[i]->width
                        ,projectile_array[j]->width
                        , actor_array[i],projectile_array[j]
                        , true
                );//intersect end

                if (temp_bool2 && !(projectile_array[j]->immunity == actor_array[i]->immunity)){

                    projectile_array[j]->lifeState = 0;
                }

            }//for 1 end

        }//for 2 end
        for (int k = 0; k < tile_array.size(); k++){ //tester for om prosjektilene krysser de solide tilesene.
            if (tile_array[k]->solid != false){
                for (int l = 0; l <projectile_array.size() ; l++) {
                    if (projectile_array[l]->getX() > tile_array[k]->nw.x && projectile_array[l]->getX() < tile_array[k]->ne.x || projectile_array[l]->getX() + projectile_array[l]->width > tile_array[k]->nw.x && projectile_array[l]->getX() + projectile_array[l]->width < tile_array[k]->ne.x) {
                        if (projectile_array[l]->getY() + projectile_array[l]->height >= tile_array[k]->nw.y && projectile_array[l]->getY() + projectile_array[l]->height <= tile_array[k]->sw.y || projectile_array[l]->getY() >= tile_array[k]->nw.y && projectile_array[l]->getY() <= tile_array[k]->sw.y) {
                            projectile_array[l]->lifeState = 0;
                        }
                    }
                }
            }
        }
    }//if end
}//Projectile_hit end
bool Collision::intersect(float x, float x2, float y, float y2, int height, int height2, int length, int length2, Actor_Class* actor_a ,Actor_Class* actor_b,bool tile) {
        if(  (x2 >= x && x2 <= x+length)  || (x2+length2 >= x && x2+length2 <= x+length)  )
        {
          if((y2 >= y && y2 <= y+height)  ||  (y2+height2 >= y && y2+height2 <= y+height))
          {
              interacting.setUp(actor_a,actor_b,x2,length2,y2,height2,tile);
              //interacting.setUp(actor_a,actor_b,x2,length2,y2,height2,tile);//det har blitt et treff object 2 coliderer med object 1

              return true;


        }//if Y end
    }//if X end
    return false;

}//intersect end
int Collision::spawnTester(int kameraLoc,int kameray) {
    for (int i = 0; i < spawn_array.size(); i++){
        if(spawn_array[i]->ne.x > kameraLoc && spawn_array[i]->ne.x < (kameraLoc+conf.windowWidth) && spawn_array[i]->spawnTest == false) {
            if (spawn_array[i]->ne.y > kameray && spawn_array[i]->se.y < kameray + conf.windowHeight) {
                spawn_array[i]->spawnTest = true;
                return i;
            }
        }
    }
    return -1;
}