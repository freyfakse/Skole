//
// Created by kab95 on 18.10.2016.
//

#ifndef HM_PROJECT_SUPER_STATE_H
#define HM_PROJECT_SUPER_STATE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



class Super_State {
public:
    int stateid =0;
    int level = -1;
   void switchTo(); // funksjon kalt på for å bytte til barnets state
};


#endif //HM_PROJECT_SUPER_STATE_H
