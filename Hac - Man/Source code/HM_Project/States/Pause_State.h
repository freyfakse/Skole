//
// Created by Jonas on 02.11.2016.
//

#ifndef HM_PROJECT_PAUSE_STATE_H
#define HM_PROJECT_PAUSE_STATE_H

#include "Super_State.h"
#include "../config.h"

class Pause_State : public Super_State{

public:
    Pause_State(sf::RenderWindow& window, int kameraPos, int kameraPosY, sf::View& camera);
    void switchTo();

    sf::RenderWindow& window;
    bool isEscPressed = false;

    int selected = 0;

    bool upKey, downKey;
};


#endif //HM_PROJECT_PAUSE_STATE_H
