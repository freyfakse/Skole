//
// Created by MORTEN on 06.12.2016.
//

#ifndef HM_PROJECT_LEVELSWICH_H
#define HM_PROJECT_LEVELSWICH_H
#include "Super_State.h"
#include "../config.h"

class levelswich : public Super_State{
public:

levelswich(sf::RenderWindow& window, int kameraPos, int kameraPosY,int level,int previiuslevl, sf::View& camera);
    void switchTo();

    sf::RenderWindow& window;
    bool isEscPressed = false;

    int selected = 0;
    bool upKey, downKey;
};




#endif //HM_PROJECT_LEVELSWICH_H
