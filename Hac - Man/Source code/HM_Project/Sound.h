//
// Created by Lars on 25.10.2016.
//

#ifndef HM_PROJECT_SOUND_H
#define HM_PROJECT_SOUND_H

#include <SFML/Audio.hpp>

class Sound
{
public:
    /// load sounds
    /// \return
    Sound();
    ///play jump sound
    void playJump();
    ///play shoot sound
    void playShoot();
    ///playhit
    void playHit();
    void playHitEnemy();


    sf::Sound jump;
    sf::Sound shoot;
    sf::Sound hit;
    sf::Sound hitEnemy;
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer shootBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer hitEnemyBuffer;
   // sf::Music bGMusic;
};


#endif //HM_PROJECT_SOUND_H
