//
// Created by Jonas on 24.10.2016.
//

#ifndef HM_PROJECT_SETTINGS_STATE_H
#define HM_PROJECT_SETTINGS_STATE_H

#include "Super_State.h"
#include "wtypes.h"

class Settings_State : public Super_State{

public:
    Settings_State(sf::RenderWindow& window);
    void switchTo();
    void GetDesktopResolution();

    int horizontal;
    int vertical;
    sf::Font* font;
    sf::Text text1;
    sf::Text text2;
    sf::Text text3;
    sf::Text text4;
    sf::Text text5;
    sf::Text text6;

    sf::RenderWindow& window;
};


#endif //HM_PROJECT_SETTINGS_STATE_H
