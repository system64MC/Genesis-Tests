#ifndef _PLAYFIELD_H_
#define _PLAYFIELD_H_

#include <genesis.h>

Map* colmap;

typedef struct
{
    u32 posX;
    u32 posY;
    Map* map;
    Map* colmap;
} Playfield;

// Sets the position of a playfield
void scrollPlayfieldToPos(Playfield* playfield, u32 x, u32 y);

#endif