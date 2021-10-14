#include<genesis.h>
#include "actor.h"
#include "player.h"
#include "sprites.h"
#include "playfield.h"

// Move the player

// inits the player at xy coordinates and returns a pointer to the player struct
Actor* playerInit(x, y)
{
    Actor player = {
        .type = PLAYER,
        .posX = x,
        .posY = y,
        .velX = 0,
        .velY = 0,
        .height = 8,
        .width = 32,
        .spr = SPR_addSprite(
                            &playerSpr,
                            x,
                            y,
                            TILE_ATTR(PAL3, 0, FALSE, FALSE)
                            )
    };

    return &player;
}

Actor player = {
    .type = PLAYER,
    .height = 32,
    .width = 32,
};

// Actor* player = malloc(sizeof(Actor));

void playerSetSprite(Actor* player)
{
    player->spr = SPR_addSprite(&playerSpr, player->posX, player->posY, TILE_ATTR(PAL3, 0, FALSE, FALSE));
}

void playerSetCoordinates(Actor* player, s16 x, s16 y)
{
    player->posX = x;
    player->posY = y;
    SPR_setPosition(player->spr, x, y);
}

void playerMove(Actor* player)
{
    if(player->type == PLAYER)
    {
        VDP_drawTextBG(BG_A, "Player Moved!", 0, 0);
        // We should get input to do something
    }
}

void playerUpdate(Actor* player)
{
    if(!JoyDown(BUTTON_C))
    {
        if(JoyDown(BUTTON_RIGHT)) playerSetCoordinates(player, player->posX + 2, player->posY);
        if(JoyDown(BUTTON_LEFT)) playerSetCoordinates(player, player->posX - 2, player->posY);
        if(JoyDown(BUTTON_UP)) playerSetCoordinates(player, player->posX, player->posY - 2);
        if(JoyDown(BUTTON_DOWN)) playerSetCoordinates(player, player->posX, player->posY + 2);
    }
    else
    {
        if(JoyDown(BUTTON_RIGHT)) playerSetCoordinates(player, player->posX + 1, player->posY);
        if(JoyDown(BUTTON_LEFT)) playerSetCoordinates(player, player->posX - 1, player->posY);
        if(JoyDown(BUTTON_UP)) playerSetCoordinates(player, player->posX, player->posY - 1);
        if(JoyDown(BUTTON_DOWN)) playerSetCoordinates(player, player->posX, player->posY + 1);
    }
    if(MAP_getTile(colmap, (player->posX >> 3) >> 1, (player->posY >> 3) >> 1) == 0) KLog("Collision !");
}