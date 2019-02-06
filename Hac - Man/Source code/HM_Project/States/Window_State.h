//
// Created by Jonas on 16.11.2016.
//

#ifndef HM_PROJECT_WINDOW_STATE_H
#define HM_PROJECT_WINDOW_STATE_H

#include "Super_State.h"

class Window_State : public Super_State{

public:
    //Menu_State();
    Window_State();
    void switchTo();

    /*

protected:
    int chooser = 0; //brukes for å velge mellom spill (Game_State) og innstillinger (Settings_State).

    */
};

#endif //HM_PROJECT_WINDOW_STATE_H
