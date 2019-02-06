//
// Created by kab95 on 06.11.2016.
//

#include "Level.h"
Level::Level(std::string levelLocI,std::string tileTextureI, int lengthI, int heightI, int tilesizeI){
    levelLoc = levelLocI;
    tileTexture = tileTextureI;
    length = lengthI;
    height = heightI;
    tilesize = tilesizeI;
}