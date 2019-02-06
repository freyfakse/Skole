//
// Created by kab95 on 18.10.2016.
//

#ifndef HM_PROJECT_GAME_STATE_H
#define HM_PROJECT_GAME_STATE_H
#include "Super_State.h"
#include "../Actor/Hero.h"
#include "../Tile/Super_Tile.h"
#include "../Level.h"

//#include "Projectile.h"


class Game_State : public Super_State {

public:
    /// constructs the game_state mak
    /// \param window window gamestate is drawn in
    /// \return
    Game_State(sf::RenderWindow& window,int level,Config& conf, sf::View& camera);
    void switchTo();
    sf::Music BGM;
    bool switchLevel(Tilemap* map, std::vector<Level> levelLocArray, bool test, Config* conf,int level);
    void FirewallCam(int firewallX);
    sf::View camMov(sf::View camera, Hero helt);
    Collision spawn(Collision col);
    void actorAct();

protected:
    bool firewallTest = false;
    bool firewallLevel = false;
    int lastFirewallX;
    int shakeVar = 0;
    int kameraX;
    int kameraY;
    int kameraPos = 0;
    int kameraSpeed = 5;
    int spawningActor = 1;
    int spawningEnemyType;
    Tilemap map;
    Tilemap map2;
    Config& conf;
    sf::RenderWindow& window;
    std::vector<Actor_Class*> actor_array;
    sf::View camera2;
};


#endif //HM_PROJECT_GAME_STATE_H
