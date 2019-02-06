//
// Created by MORTEN on 20.10.2016.
//

#ifndef HM_PROJECT_CONFIG_H
#define HM_PROJECT_CONFIG_H
#include "Level.h"

class Config {
public:

    int windowWidth =  1024;
    int windowHeight = 512;
    int startCamHeight;
    int currentLevel;// nummeret til levelen som gamestate loadet inn
    std::vector<Level> levelLocArray; // et array som brukes til å lage et level ut av
    int bgVolume = 0;
/// loader alle levelene å holder informasjon om levelen som er loadet inn
/// \return
    Config(){
        Level levelInn("Resources/Level1.txt", "Resources/tileset transparency.png",164,16,32); //tar inn verdiene for antalll tiles i lengden først, så antall tiles i høyed og deretter tilestøttelse (sannsynligvis best å ikke tukle med denne verdien ved mindre du har lyst til å justere teksturfilen og et par andre verdier i tilemap i tillegg.)
        levelLocArray.push_back(levelInn);
        Level levelInn2("Resources/Level2.txt","Resources/tileset transparency.png",102,16,32);
        levelLocArray.push_back(levelInn2);
        Level levelInn3("Resources/Level3.txt","Resources/tileset.png",164,16,32);
        levelLocArray.push_back(levelInn3);
        Level levelInn4("Resources/Level4.txt","Resources/tileset.png",100,16,32);
        levelLocArray.push_back(levelInn4);
        Level levelInn5("Resources/Level5.txt","Resources/tileset alternativ.png",164,16,32);
        levelLocArray.push_back(levelInn5);
        Level levelInn6("Resources/Level6.txt", "Resources/tileset alternativ.png",121,16,32);
        levelLocArray.push_back(levelInn6);
        Level levelInn7("Resources/LevelCredits.txt", "Resources/tilesExtended.png",32,16,32);
        levelLocArray.push_back(levelInn7);
    }
    void loadedLevel(int loadedLevel){
        this->currentLevel = loadedLevel;
    }
    int getLevelLength(){
        return levelLocArray[currentLevel].length * (levelLocArray[currentLevel].tilesize);
    }
    int getLevelHeight(){
        return levelLocArray[currentLevel].height * levelLocArray[currentLevel].tilesize;
    }
    int getLevelTileSize(){
        return levelLocArray[currentLevel].tilesize;
    }
    int getStartCamHeight(int heroSpawnY){ //beregner dynamisk hvor kameraet skal plasseres på y aksen

        if((this->getLevelHeight()-heroSpawnY) < heroSpawnY){ //tester distansen fra hero til kantene på skjermen og plasserer kameraet enten til 0 eller til en skjermlengde mindre en total størrelse på nivået
            startCamHeight = this->getLevelHeight()-this->windowHeight;
            if (heroSpawnY < startCamHeight){ // tester for om kameraet eventuelt da vill plasseres ovenfor helten og plasserer eventuelt kameraet en halv skjermlengde over helten som kompromiss.
                startCamHeight = heroSpawnY-this->windowHeight/2;
            }
        }
        else{
            startCamHeight = 0;
            if (heroSpawnY > this->windowHeight){// tester for om kameraet eventuelt da vill plasseres ovenfor helten og plasserer eventuelt kameraet en halv skjermlengde over helten som kompromiss.
                startCamHeight = heroSpawnY-this->windowHeight/2;
            }
        }
        return startCamHeight;
    }
    void selectLevel()
    {
        while(true) {
            std::cout << "trykk 0,1,2 eller 3 for forskjellige leveler";
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                this->currentLevel = 4;
                this->loadedLevel(4);

                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                this->currentLevel = 4;
                this->loadedLevel(4);

                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                this->currentLevel = 4;
                this->loadedLevel(4);

                return;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                this->currentLevel = 3;
                this->loadedLevel(3);

                return;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {

                this->currentLevel = 4;
                this->loadedLevel(4);

                return;
            }
        }
    }
};


#endif //HM_PROJECT_CONFIG_H
