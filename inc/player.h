#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <genesis.h>
#include "actor.h"
extern Actor player;

Actor* playerInit(int x, int y);
void playerSetSprite(Actor* player);
void playerSetCoordinates(Actor* player, s16 x, s16 y);
void playerUpdate(Actor* player);

// Move the player, you need to pass an Actor argument
void playerMove(Actor* player);

s16 getCollisionPosX(s16 x, s16* ys, u16 array_size);
s16 getCollisionPosY(s16* xs, s16 y, u16 array_size);

#define GRAVITY 2

#endif