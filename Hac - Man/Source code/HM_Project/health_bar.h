//
// Created by MORTEN on 08.12.2016.
//

#ifndef HM_PROJECT_HEALTH_BAR_H
#define HM_PROJECT_HEALTH_BAR_H


#include <SFML/Graphics.hpp>
#include "iostream"
#include "Super_Class.h"
#include "Config.h"

class health_bar : public Super_Class {


protected:

    sf::RenderWindow& vindu;
    std::string temp;


public:
    /// functionen tar in winduet og lager healtbar objectet
    /// \param window
    /// \param conf
    /// \return
    health_bar(sf::RenderWindow& window, Config& conf);

    /// oppdaterer fremvisningen av liet til hero og bosser
    /// \param lives livet til spiller / hero
    /// \param boss livet til boss
    void update(int lives, int boss);
    /// tegner opp vinduet i spillet
    /// \param kameraPos
    /// \param kameraPosY
    void draw(int kameraPos, int kameraPosY);

    sf::Text health; // texten som viser livet til helten og bossen
    sf::Font font; // fonten til texten som blir vist
    Config& conf; // config brukes for å få vindustørrelsen på spillet

};




#endif //HM_PROJECT_HEALTH_BAR_H
