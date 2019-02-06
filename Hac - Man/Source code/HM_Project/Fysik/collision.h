//
// Created by MORTEN on 24.10.2016.
//

#ifndef HM_PROJECT_COLLISION_H
#define HM_PROJECT_COLLISION_H

#include "vector"
#include "../Actor/actor_class.h"
#include "iostream"
#include "../Actor/projectil/projectile.h"
#include "interacting.h"
#include "../Tile/Tilemap.h"
#include "../Tile/Super_Tile.h"
#include "../Tile/action_tile/Spawn_Tile.h"
#include "../config.h"
#include "../Sound.h"


class Collision {
protected:
    bool temp_bool ;
public:
    Config conf;//inneholder alle levelene pluss informajon om de
    Sound sound;

   /// constructor
   /// \return
    Collision(Config confInn){conf = confInn; };

    void  collisionDetection(std::vector<Actor_Class*> arry);
    /// This function test if 2 objects whith x,y,height,length colide
    /// \param x
    /// \param x2
    /// \param y
    /// \param y2
    /// \param height
    /// \param height2
    /// \param length
    /// \param length2
    /// \param actor_a
    /// \param actor_b
    /// \return

    bool intersect(float x,float x2,float y,float y2, int height,int height2,int length,int length2, Actor_Class* actor_a, Actor_Class* actor_b,bool tile);
    /// this function checks if a projectile hits a actor
    /// \param actor_array
    void projectile_hit(std::vector<Actor_Class*> actor_array);
    /// this function imports the array that holds all the projectils to collisionDetection
    /// \param imported_projectile_array
    void import_projectiles(std::vector<Projectile*> imported_projectile_array);
    /// this function imports tiles to collisionDetectio
    /// \param imported_tile_array
    void import_map(std::vector<Super_Tile*> imported_tile_array, std::vector<Action_Tile*>imported_actiontile_array, std::vector<Spawn_Tile *> imported_spawn_array);
    /// this function checks if an actor colides with the tiles
    /// \param actor
    /// \return
    bool tileCollision( Actor_Class* actor);
    /// En funcsion som tester om en spawn tile er innenfor kamraet
    /// \param kameraLoc
    /// \param kameray
    /// \return
    int spawnTester(int kameraLoc,int kameray);
    /// sjekker om actor koliderer med en actiontile
    /// \param actor
    void actiontileCollision(Actor_Class* actor);

    interacting interacting;//et instanse an interacting som brukes til å kjøre en function som som sjekker hvilken funksjon eller effekt som skjer på actorene
    std::vector<Projectile*> projectile_array;//et array med alle projectilene i spillet
    std::vector<Super_Tile*> tile_array;//et array med alle standar tilene i spillet
    std::vector<Action_Tile*> actiontile_array;//et array med alle actiotilene i spillet
    std::vector<Spawn_Tile*> spawn_array;//et array med alle spawn tilene i spillet

};


#endif //HM_PROJECT_COLLISION_H
