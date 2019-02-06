//
// Created by kab95 on 18.10.2016.
//

#ifndef HM_PROJECT_MENU_STATE_H
#define HM_PROJECT_MENU_STATE_H

#include "Super_State.h"
#include "game_state.h"
#include "settings_state.h"
#include "../config.h"


class menu_state : public Super_State{

public:
  menu_state(sf::RenderWindow& window, sf::View& camera);
    void switchTo();
    sf::Texture backTexture;
    sf::Sprite menuImage;
    sf::Clock clock;

    void Menu_State();
   //void switchTo();
    void draw_background();

    sf::RenderWindow& window;
protected:
    int chooser = 0; //brukes for å velge mellom spill (Game_State) og innstillinger (Settings_State).
    int selected = 0;

    bool upKey, downKey;
};


#endif //HM_PROJECT_MENU_STATE_H
