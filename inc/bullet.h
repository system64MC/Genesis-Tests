#ifndef _BULLET_H_
#define _BULET_H_
#include <genesis.h>

typedef struct 
{
    int xPos;
    int yPos;
    uint8_t isDead; // Zero if alive, One or more if dead, dead bullets aren't updated...
    s16 angle; // direction of the bullet
    uint8_t speed; // speed of the bullet
    // both of angle and speed compose a vector which will be used to move the bullet
} Bullet;

Bullet bulletsBuf[128];


void spawnBullet(int x, int y, int angle, int speed);
void killBulet(Bullet* bullet);
void bulletUpdate(Bullet* bullet);
void initBulletBuf();

#endif