//
// Created by kab95 on 06.11.2016.
//

#ifndef HM_PROJECT_LEVEL_H
#define HM_PROJECT_LEVEL_H
#include <iostream>

class Level {

public:
    /// fuctionen lagrer en string av ett notpad document pluss at den lagrer størrelsene på tilsene pluss lengden å høyden på levelet
    /// \param levelLocI
    /// \param tileTextureI
    /// \param lengthI
    /// \param heightI
    /// \param tilesizeI
    /// \return
    Level(std::string levelLocI,std::string tileTextureI, int lengthI, int heightI, int tilesizeI);

    std::string levelLoc;
    std::string tileTexture;
    int length;
    int height;
    int tilesize;
};


#endif //HM_PROJECT_LEVEL_H
