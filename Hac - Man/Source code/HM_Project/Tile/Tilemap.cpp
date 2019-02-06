//
// Created by kab95 on 31.10.2016.
//

#include "Tilemap.h"
#include "Finnish_tile.h"

std::vector<int> Tilemap::loadMapFromFile(std::string levelLoc){
    std::ifstream infile(levelLoc);
    std::string line;
    std::vector<int> levelText;
    levelText.clear();
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int n;

        while (iss >> n)
        {
            levelText.push_back(n);
        }

    }
    return levelText;
}

bool Tilemap::load(Level lastetLevel){

    length = lastetLevel.length;
    height = lastetLevel.height;
    tilesize = lastetLevel.tilesize;

    Config conf;
    //int tileLengde = conf.windowWidth/width;
    //int tileHoyde = conf.windowHeight/height; //tidligere forsøk på å endre størrelse på tilesne i forhold til skjermen. Fant ettervert ut at det ikke var nødvendig.
    std::vector<int> level = loadMapFromFile(lastetLevel.levelLoc);


    if(destroyed == false){
        tileTexture.loadFromFile(lastetLevel.tileTexture);
    }
    else
    {
        tileTexture.loadFromFile("Resources/tilesDestroyed.png");
    }


    tiles.setPrimitiveType(sf::Quads);//tiles er en serie med firkanter
    tiles.resize((lastetLevel.length*lastetLevel.height)*4); //endrer størrelsen på arrayet til størrelsen på text filen ganger 4 for alle de individuelle punktene.

    for (int i = 0; i < lastetLevel.length; ++i) {
        for (int j = 0; j < lastetLevel.height; ++j) {
            int tileNumber = level[i + j * lastetLevel.length];
            int temp = tileTexture.getSize().x / lastetLevel.tilesize; //fikk en rar feil med float uten temp. implementerte temp for å unngå feilen.
            // find position in the tileset texture
            int tu = tileNumber % (temp);
            int tv = tileNumber / (tileTexture.getSize().x / lastetLevel.tilesize);


            sf::Vertex *quad = &tiles[(i + j * lastetLevel.length) * 4];

            sf::Vector2f* tempVector = new sf::Vector2f(i * 32, j * 32);//legger inn koordinatene til de fire hjørnene og ganger med tile lengde.
            quad[0].position = *tempVector;

            sf::Vector2f* tempVector2 = new sf::Vector2f((i + 1) * lastetLevel.tilesize, j * lastetLevel.tilesize);
            quad[1].position = *tempVector2;

            sf::Vector2f* tempVector3 = new sf::Vector2f((i + 1) * lastetLevel.tilesize, (j + 1) * lastetLevel.tilesize);
            quad[2].position = *tempVector3;

            sf::Vector2f* tempVector4 = new sf::Vector2f(i * lastetLevel.tilesize, (j + 1) * lastetLevel.tilesize);
            quad[3].position = *tempVector4;

            quad[0].texCoords = sf::Vector2f(tu * lastetLevel.tilesize, tv * lastetLevel.tilesize); //legger til koordinatene på teksturene i .png filene.
            quad[1].texCoords = sf::Vector2f((tu + 1) * lastetLevel.tilesize, tv * lastetLevel.tilesize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * lastetLevel.tilesize, (tv + 1) * lastetLevel.tilesize);
            quad[3].texCoords = sf::Vector2f(tu * lastetLevel.tilesize, (tv + 1) * lastetLevel.tilesize);

            if(tileNumber >= 1 && tileNumber <= 18){ //om tilen er solid legger den til i arrayen.
                Solid_Tile* solidTile= new Solid_Tile(tempVector,tempVector2,tempVector3, tempVector4);
                solidTileList.push_back(solidTile);
                tileList.push_back(solidTile);
            }
            if(tileNumber ==19){ //om tilen er solid legger den til i arrayen.
                Semisolid_Tile* semisolidTile= new Semisolid_Tile(tempVector,tempVector2,tempVector3, tempVector4);
                tileList.push_back(semisolidTile);
            }
            if(tileNumber >= 20 && tileNumber <= 23){
                Spike_Tile* spikeTile = new Spike_Tile(tempVector,tempVector2,tempVector3, tempVector4);
                spikeTile->direction = tileNumber-20; //betegner hvilken retning spike tilen henger
                actionTileList.push_back(spikeTile);
                //tileList.push_back(spikeTile);
            }
            if(tileNumber == 24 || tileNumber == 25){
                Speed_Tile* speedTile = new Speed_Tile(tempVector,tempVector2,tempVector3, tempVector4);
                speedTile->direction = tileNumber-24;
                actionTileList.push_back(speedTile);
                tileList.push_back(speedTile);
            }
            if(tileNumber == 30){
                Finnish_tile* finnish_tile = new Finnish_tile(tempVector,tempVector2,tempVector3, tempVector4);
               // finnish_tile->import(/*&conf,*/this);
                tileList.push_back(finnish_tile);

            }

            if(tileNumber >= 80 && tileNumber <= 99){
                Spawn_Tile* spawnTile = new Spawn_Tile(tempVector,tempVector2,tempVector3, tempVector4, tileNumber);
                if(tileNumber == 99){heroSpawn = spawnTile;}
                else {
                    spawnTileList.push_back(spawnTile);
                }
            }

        }
    }
    return true;
}
