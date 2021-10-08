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

#endif