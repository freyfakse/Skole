//
// Created by kab95 on 31.10.2016.
//

#ifndef HM_PROJECT_TILEMAP_H
#define HM_PROJECT_TILEMAP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../config.h"
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Super_Tile.h"
#include "Solid_Tile.h"
#include "Semisolid_Tile.h"

#include "action_tile/Spike_Tile.h"
#include "action_tile/Speed_Tile.h"
#include "../Level.h"
#include "action_tile/Spawn_Tile.h"


class Tilemap : public sf::Drawable, public sf::Transformable {
public:

    std::vector<Super_Tile*> tileList;
    std::vector<Solid_Tile*> solidTileList;
    std::vector<Action_Tile*> actionTileList;
    std::vector<Spawn_Tile*> spawnTileList;
    Spawn_Tile* heroSpawn;
    /// Laster inn txt filen og plasserer tallene in en array.
    /// \param levelLoc stedet hvor levelen er lagret
    /// \return
    std::vector<int> loadMapFromFile(std::string levelLoc);
    /// Laster inn teksturer og mapper dem til skjermen. Lagrer solide tiles inn i et array kalt tileList
    /// \param levelLoc
    /// \return
    bool load(Level lastetLevel);
    void sortSpawnList();

    int length;
    int height;
    int tilesize;

    bool destroyed = false;
private:
    /// Legger inn teksturer og tegner til vinduet(target), states virker releveant for drawable klassen Tilemap arver fra.
    /// \param target
    /// \param states
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &tileTexture;
        target.draw(tiles, states);
    }


    sf::VertexArray tiles;
    sf::Texture tileTexture;
};


#endif //HM_PROJECT_TILEMAP_H
