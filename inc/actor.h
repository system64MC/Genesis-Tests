#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <genesis.h>

enum ActType
{
    PLAYER,
    ENNEMY
};

typedef struct
{
    u8 type;    // Type of actor
    s16 posX;   // position in X cordinates
    s16 posY;   // position in Y cordinates  
    s16 velX;   // velocity in X cordinates
    s16 velY;   // velocity in Y cordinates
    s16 width;  // width of the sprite
    s16 height; // height of the sprite
    // pointing to the sprite
    Sprite* spr;// pointer to the sprite
} Actor;



#endif // _ACTOR_H_
