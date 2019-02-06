//
// Created by Tore Ky Quan Lam on 12/9/2016.
//

#ifndef HM_PROJECT_SELECTLVL_STATE_H
#define HM_PROJECT_SELECTLVL_STATE_H

#include "Super_State.h"
#include "game_state.h"
#include "../config.h"
#include "menu_state.h"

class selectlvl_state : public Super_State{

public:
    selectlvl_state(sf::RenderWindow& window,int current);
    void switchTo();

    sf::RenderWindow& window;

    sf::Text title;
    sf::Text text;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    sf::Text text6;
    sf::Text text7;



protected:
    int selected = 0;

    bool upKey, downKey;
};

#endif //HM_PROJECT_SELECTLVL_STATE_H