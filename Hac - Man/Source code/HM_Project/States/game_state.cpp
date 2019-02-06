//
// Created by kab95 on 18.10.2016.
//

#include "game_state.h"
#include "../game_timer.h"
#include "../Actor/projectil/Shooting_Mechanic.h"
#include "../Actor/enemy/enemy_goomba.h"
#include "../Actor/enemy/Flying_enemy.h"
#include "../Actor/enemy/boss_fight_1.h"
#include "../Actor/enemy/boss_enemy_2.h"
#include "../Actor/enemy/Firewall.h"
#include "Pause_State.h"
#include "levelswich.h"
#include "../Actor/enemy/Boss_door.h"
#include "../health_bar.h"
#include "../Actor/enemy/turret.h"
#include "../Actor/enemy/health_item.h"
#include "../Actor/enemy/boss_fight_3.h"
#include "../Actor/enemy/turret_S.h"
#include "../Actor/enemy/turret_N.h"
#include "../Actor/enemy/turret_E.h"
#include "../Actor/enemy/turret_W.h"
#include "../Actor/enemy/turret_all.h"
#include "../Actor/Textbox.h"


Game_State::Game_State(sf::RenderWindow& window,int level,Config& conf,sf::View& camera) : window(window), conf(conf) {

    Game_Timer timer(window); //starter timer på nivået
    health_bar healthBar(window, conf);
    bool test2 = false;


    map2.destroyed = true;//setter tilesettet til firewall kameraet.
    while(!test2) {
        test2 = switchLevel(&map, conf.levelLocArray, test2, &conf,level); //endrer currentLevel i config
    }
    map2.load(conf.levelLocArray[conf.currentLevel]);//Laster inn teksturene til nivået i Tilemap objektet og legger tiles inn i relevante arrays
    //camera2.reset(sf::FloatRect(0,conf.getStartCamHeight(map.heroSpawn->nw.y),conf.windowWidth/2,conf.windowHeight));
    camera2.reset(sf::FloatRect(0,conf.getStartCamHeight(map.heroSpawn->nw.y),conf.windowWidth/2,conf.windowHeight)); //Initialiserer camera2
    camera2.setViewport(sf::FloatRect(0,0,0,1));

    camera.reset(sf::FloatRect(0,conf.getStartCamHeight(map.heroSpawn->nw.y),conf.windowWidth,conf.windowHeight));//initialiserer camera
    kameraX = conf.windowWidth/2; //initialiserer variabler
    kameraY = conf.getStartCamHeight(map.heroSpawn->nw.y);
    kameraPos = 0;
    kameraSpeed = 5;
    spawningActor = 1;
    spawningEnemyType;
    Collision col(conf);
    col.import_map(map.tileList, map.actionTileList,map.spawnTileList); //
    Shooting_Mechanic shot(window, &col, conf);//implementerer collision på nivået

    Hero helt(window, col,map.heroSpawn->ne.x,map.heroSpawn->ne.y);//create player character
    helt.lvl= conf.currentLevel;
    actor_array.push_back(&helt); //initialiserer flyttingen til helt

    //starter opp bakgrunnsmusikk avhangig av level
    if(conf.currentLevel == 0)
    {
        if (!BGM.openFromFile("Resources/BGM_3_1.wav"))
        {
            std::cout << "Failed to load BGM_3_1.wav" << std::endl;
        }

        //BGM.setVolume(10);
        BGM.play();
        BGM.setLoop(true);
    }

    if(conf.currentLevel == 1)
    {
        if (!BGM.openFromFile("Resources/BGM_3_1.wav"))
        {
            std::cout << "Failed to load BGM_3_1.wav" << std::endl;
        }

        //BGM.setVolume(10);
        BGM.play();
        BGM.setLoop(true);
    }

    if(conf.currentLevel == 2)
    {
        if (!BGM.openFromFile("Resources/BGM_2_1.wav"))
        {
            std::cout << "Failed to load BGM_2_1.wav" << std::endl;
        }

        //BGM.setVolume(10);
        BGM.play();
        BGM.setLoop(true);
    }

    if(conf.currentLevel == 3)
    {
        if (!BGM.openFromFile("Resources/BGM_2_1.wav"))
        {
            std::cout << "Failed to load BGM_2_1.wav" << std::endl;
        }

        //BGM.setVolume(10);
        BGM.play();
        BGM.setLoop(true);
    }

    if(conf.currentLevel == 4)
    {
        if (!BGM.openFromFile("Resources/BGM_1.wav"))
        {
            std::cout << "Failed to load BGM_1.wav" << std::endl;
        }

        //BGM.setVolume(100);
        BGM.play();
        BGM.setLoop(true);
    }

    if(conf.currentLevel == 5)
    {
        if (!BGM.openFromFile("Resources/BGM_1.wav"))
        {
            std::cout << "Failed to load BGM_1.wav" << std::endl;
        }

        //BGM.setVolume(100);
        BGM.play();
        BGM.setLoop(true);
    }

    // Run the game loop as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;

        // Read all events from the window
        while (window.pollEvent(event))
        {
            // Quit when the user presses 'x', ignore all other events
            if (event.type == sf::Event::Closed)
                window.close();
        }

        col = spawn(col); //spawner fiender fra tiles

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //pauser spillet
        {

            Pause_State pause(window,kameraPos, kameraY, camera);
            this->level = pause.level;
            this->stateid = pause.stateid;
            if(pause.stateid != -1 ) {
                this->stateid = pause.stateid;
                return;
            }
        }
        if(helt.lvl != conf.currentLevel || helt.lifeState == 0){ //går inn i levelswich
            this->level = -1;
            while (this->level == -1){

            levelswich level(window,kameraPos,kameraY,helt.lvl,conf.currentLevel,camera);
            this->level = level.level;
            this->stateid = level.stateid;

            }
            return;
        }
        //flytter kameraet
        camera = camMov(camera,helt); //flytter kameraet avhengig av hero sin posisjon

        // Clear the window to black
        window.clear();
        window.setView(camera);//setter vinduet sitt kameraet til camera
        window.draw(map);//tegner nivået

        actorAct(); //kjører gjennom flyttingen av aktører
        shot.heroShot(&helt, kameraPos); //tester for skyting fra hero
        shot.enemyshot(actor_array,kameraPos); //tester for skyting fra fiender

        col.projectile_hit(actor_array); //sjekker for om skudd treffer
        col.collisionDetection(actor_array); //kjører gjennom kollision detection
        shot.draw();//tegner skudd
        col.import_map(map.tileList, map.actionTileList,map.spawnTileList);
        // Flip the back buffer and front buffer, showing what was drawn


        //alle bossene har immunty 5

        for (int i = 0; i <actor_array.size() ; ++i) { //oppdaterer healthbar

            healthBar.update(helt.lifeState, -1);
            if(actor_array[i]->immunity == 5){
                healthBar.update(helt.lifeState,actor_array[i]->health);
                i = actor_array.size();
            }

        }


        healthBar.draw(kameraPos,kameraY);
        timer.teller();
        timer.draw(kameraPos, kameraY);

        if(firewallLevel) {//setter opp firewall kameraet om firewall har spawnet i levelen.
            window.setView(camera2);
            window.draw(map2);
        }
        window.display();
    }

    return;
}
void Game_State::actorAct(){
    firewallTest = false;
    for (int i = 0; i < actor_array.size(); i++){ //flytter og tegner alle actor i spillet.
        actor_array[i]->jump();
        actor_array[i]->move();
        actor_array[i]->action();
        actor_array[i]->interaction(actor_array);
        actor_array[i]->draw();


        if(actor_array[i]->actorid == 92){
            firewallTest = true;
            FirewallCam(actor_array[i]->getX());

        }
        if (actor_array[i]->lifeState== 0){
            actor_array.erase(actor_array.begin()+i);

        }
    }

    if (firewallTest == false && firewallLevel == true){

        FirewallCam(lastFirewallX);


        if(actor_array[0]->getX() < lastFirewallX){
            actor_array[0]->lifeState--;


        }
    }
}

void Game_State::switchTo(){}

Collision Game_State::spawn(Collision col){
            spawningActor = col.spawnTester(kameraPos,kameraY);
        //legger til goomba hvis g trykkes
        if(spawningActor != -1) {
            spawningEnemyType = map.spawnTileList[spawningActor]->spawn();
            if (spawningEnemyType == 90 || spawningEnemyType == 99){
                Enemy_Goomba *addGoomba = new Enemy_Goomba(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y-50);
                actor_array.push_back(addGoomba);
            }
            if (spawningEnemyType == 91)
            {
                Flying_enemy *addCorrupted = new Flying_enemy(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y, conf);
                actor_array.push_back(addCorrupted);
            }
            if(spawningEnemyType == 92)
            {
                Firewall *addfirewall = new Firewall(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y,map.length);
                actor_array.push_back(addfirewall);
            }
            if(spawningEnemyType == 93)
            {
                boss_fight_1 *addboss = new boss_fight_1(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(addboss);
            }
            if(spawningEnemyType == 94)
            {
                Boss_door *door = new Boss_door(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(door);
            }

            //Turrets
            if(spawningEnemyType == 80)
            {
                turret_W *turrW = new turret_W(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turrW);
            }
            if(spawningEnemyType == 81)
            {
                turret_E *turrE = new turret_E(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turrE);
            }
            if(spawningEnemyType == 82)
            {
                turret_N *turrN = new turret_N(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turrN);
            }
            if(spawningEnemyType == 83)
            {
                turret_S *turrS = new turret_S(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turrS);
            }
            if(spawningEnemyType == 84)
            {
                turret *turr = new turret(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turr);
            }
            if(spawningEnemyType == 85)
            {
                turret_all *turra = new turret_all(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(turra);
            }
            //Turrets end

            if(spawningEnemyType == 96) {
                boss_enemy_2 *addboss2 = new boss_enemy_2(window, col, map.spawnTileList[spawningActor]->nw.x,
                                                          map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(addboss2);
            }
            if(spawningEnemyType == 97)
                {
                    health_item *heart = new health_item(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                    actor_array.push_back(heart);
                }

            if(spawningEnemyType == 98)
            {
                boss_fight_3 *addboss3 = new boss_fight_3(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                actor_array.push_back(addboss3);
            }

            if(spawningEnemyType == 86 || spawningEnemyType <=89 && spawningEnemyType > 86 )
            {
                Textbox *textbox = new Textbox(window, col, map.spawnTileList[spawningActor]->nw.x, map.spawnTileList[spawningActor]->nw.y);
                textbox->loadText(spawningEnemyType-86);
                actor_array.push_back(textbox);
            }
        }
    return col;
}

sf::View Game_State::camMov(sf::View camera, Hero helt){
    //flytter kameraet på y aksen
    if (helt.getY() < (kameraY + conf.windowHeight / 4) && kameraY > 0) { //flytter kameraet om spiller ligger på øverste delen av skjermen.
        kameraY -= kameraSpeed;
        camera.move(0, -kameraSpeed);
        //kameraPos -= kameraSpeed * 4;
    }
    else if(helt.getY() > (kameraY + (3*conf.windowHeight / 4))&& kameraY+conf.windowHeight < conf.getLevelHeight()){//flytter kameraet raskt nedover om spiller er på nedre fjeredel
        kameraY += 4*kameraSpeed;
        camera.move(0, 4*kameraSpeed);
        if(kameraY+conf.windowHeight > conf.getLevelHeight()-20){
            kameraY = conf.getLevelHeight()-conf.windowHeight;
            //camera.move(0,(conf.getLevelHeight()-(kameraY+conf.windowHeight)));
            camera.reset(sf::FloatRect(kameraPos,kameraY,conf.windowWidth,conf.windowHeight));
        }
    }

    if(helt.getX()>(kameraX) && ((kameraPos+conf.windowWidth+2) < conf.getLevelLength())) // flytter kameraet på x aksen og forhindrer at det beveger seg forbi levelen
    { //flytter kameraet
        if(helt.getX()>(kameraX+(conf.windowWidth/4))){ //flytter kameraet lenger om spiller er for langt til høyre
            kameraX += kameraSpeed*4;
            camera.move(kameraSpeed*4,0);
            kameraPos += kameraSpeed*4;
        }
        else {
            kameraX += kameraSpeed;
            camera.move(kameraSpeed, 0);
            kameraPos += kameraSpeed;
        }
    }
    if(helt.getX()<(kameraPos+conf.windowWidth/4) && kameraPos != 0)
    {
        kameraX -= kameraSpeed;
        camera.move(-kameraSpeed, 0);
        kameraPos -= kameraSpeed;
    }

    if (firewallTest == true){

        shakeVar++;
        if(shakeVar == 1){camera.rotate(0.5); camera2.rotate(0.5);}
        if(shakeVar == 3){camera.rotate(-1); camera2.rotate(-1);}
        if(shakeVar >= 5){ shakeVar = 0; camera.rotate(0.5); camera2.rotate(0.5);}
    }
    else{camera.setRotation(0);}
    return camera;
}

void Game_State::FirewallCam(int firewallX){

    firewallLevel = true;
    lastFirewallX = firewallX;
    double ratio = firewallX-kameraPos;
    camera2.reset(sf::FloatRect(kameraPos, kameraY,ratio,conf.windowHeight));
    ratio = ratio/conf.windowWidth;
    if(firewallX > kameraPos){
        camera2.setViewport(sf::FloatRect(0,0,ratio,1));
    }
    else{camera2.setViewport(sf::FloatRect(0,0,0,0));}
}

bool Game_State::switchLevel(Tilemap* map, std::vector<Level> levelLocArray, bool test, Config* conf ,int level) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && test == false) {

        if (!map->load(levelLocArray[0])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 0;
        conf->loadedLevel(0);

        return true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && test == false) {
        if (!map->load(levelLocArray[1])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 1;
        conf->loadedLevel(1);

        return true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && test == false) {
        if (!map->load(levelLocArray[2])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 2;
        conf->loadedLevel(2);


        return true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && test == false) {
        if (!map->load(levelLocArray[3])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 3;
        conf->loadedLevel(3);

        return true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && test == false) {
        if (!map->load(levelLocArray[4])) {
            std::cout << "fikk ikke lastet inn teksturer";

        }
        conf->currentLevel = 4;
        conf->loadedLevel(4);

        return true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && test == false) {
        if (!map->load(levelLocArray[5])) {
            std::cout << "fikk ikke lastet inn teksturer";

        }
        conf->currentLevel = 5;
        conf->loadedLevel(5);

        return true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && test == false) {
        if (!map->load(levelLocArray[6])) {
            std::cout << "fikk ikke lastet inn teksturer";

        }
        conf->currentLevel = 6;
        conf->loadedLevel(6);

        return true;
    }


    if (level == 0) {
        if (!map->load(levelLocArray[0])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 0;
        conf->loadedLevel(0);

        return true;
    }
    if (level == 1) {
        if (!map->load(levelLocArray[1])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 1;
        conf->loadedLevel(1);

        return true;
    }
    if (level == 2) {
        if (!map->load(levelLocArray[2])) {
            std::cout << "fikk ikke lastet inn teksturer";
        }
        conf->currentLevel = 2;
        conf->loadedLevel(2);

        return true;
    }

    if (level == 3) {
        if (!map->load(levelLocArray[3])) {
            std::cout << "fikk ikke lastet inn teksturer";
        };
        conf->currentLevel = 3;
            conf->loadedLevel(3);
        return  true;
        }

    if (level == 4) {
        if (!map->load(levelLocArray[4])) {
            std::cout << "fikk ikke lastet inn teksturer";
        };
        conf->currentLevel = 4;
        conf->loadedLevel(4);
        return  true;
    }

    if (level == 5) {
        if (!map->load(levelLocArray[5])) {
            std::cout << "fikk ikke lastet inn teksturer";
        };
        conf->currentLevel = 5;
        conf->loadedLevel(5);
        return  true;
    }
    if (level == 6) {
        if (!map->load(levelLocArray[6])) {
            std::cout << "fikk ikke lastet inn teksturer";
        };
        conf->currentLevel = 6;
        conf->loadedLevel(6);
        return  true;
    }
    if (level == 7) {
        if (!map->load(levelLocArray[7])) {
            std::cout << "fikk ikke lastet inn teksturer";
        };
        conf->currentLevel = 7;
        conf->loadedLevel(7);
        return  true;
    }

}
