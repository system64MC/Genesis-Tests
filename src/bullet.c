#include "bullet.h"
#include <genesis.h>

void initBulletBuf()
{
    for (u8 i = 0; i < 127; i++)
    {
        Bullet bullet =
        {
            .xPos = 0,
            .yPos = 0,
            .isDead = 1,
            .angle = 0,
            .speed = 0,
        };
        bulletsBuf[i] = bullet;
    }
    
}