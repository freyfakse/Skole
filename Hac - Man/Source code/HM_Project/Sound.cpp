//
// Created by Lars on 25.10.2016.
//
#include"Sound.h"

Sound::Sound()
{
    jumpBuffer.loadFromFile("Resources/jump.wav");
    shootBuffer.loadFromFile("Resources/shoot.wav");
    hitBuffer.loadFromFile("Resources/hit_1.wav");
    hitEnemyBuffer.loadFromFile("Resources/hit_3.wav");
    jump.setBuffer(jumpBuffer);
    shoot.setBuffer(shootBuffer);
    hit.setBuffer(hitBuffer);
    hitEnemy.setBuffer(hitEnemyBuffer);
}

void Sound::playShoot()
{
    shoot.play();
}

void Sound::playJump()
{
    jump.play();
}

void Sound::playHit()
{
    hit.play();
}

void Sound::playHitEnemy()
{
    hitEnemy.play();
}