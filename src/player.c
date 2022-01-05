#include<genesis.h>
#include "actor.h"
#include "player.h"
#include "sprites.h"
#include "playfield.h"
#include "collision.h"

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
        .collisionPointX = player.posX + 12,
        .collisionPointY = player.posY + 7,
        .colHeight = 25,
        .colLenght = 8,
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
    if(player->velX != 0 || player->velY != 0)
    {
        playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);
    }
    
        if(JoyDown(BUTTON_RIGHT))
        {
            player->velX = 2;
        }
        if(JoyDown(BUTTON_LEFT))
        {
            player->velX = -2;
        } 
        if(JoyDown(BUTTON_UP))
        {
            player->velY = -2;
        } 
        if(JoyDown(BUTTON_DOWN))
        {
            player->velY = 2;
        } 

    if(player, player->velX != 0 || player->velY != 0)
    {
        playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);
    }

    // if(MAP_getTile(colmap, (player->posX >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0) 
    // {
    //     KLog("Collision !");
    //     playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    // }   
    // if(MAP_getTile(colmap, (player->posX + player->width >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0) 
    // {
    //     KLog("Collision !");
    //     playerSetCoordinates(player, ((player->posX >> 3) << 3), player->posY);
    // }
    // if(MAP_getTile(colmap, (player->posX + 16 >> 3) >> 1, (player->posY >> 3) >> 1) == 0) 
    // {
    //     KLog("Collision !");
    //     playerSetCoordinates(player, player->posX, ((player->posY >> 3) << 3) + 8);
    // }
    // if(MAP_getTile(colmap, (player->posX + 16 >> 3) >> 1, (player->posY + 32 >> 3) >> 1) == 0) 
    // {
    //     KLog("Collision !");
    //     playerSetCoordinates(player, player->posX, ((player->posY >> 3) << 3));
    // }

    // if(isTileSolid(player->posX, player->posY, player->posX + 32, player->posY + 32, colmap)) KLog("Collision!");


    //Vertical Collisions
    if(MAP_getTile(colmap, (player->posX >> 3) >> 1, (player->posY >> 3) >> 1) == 0 && player->posX - (player->posX >> 3) >> 1 > 0) 
    {
        KLog("Collision !");
        playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }

    else if(MAP_getTile(colmap, (player->posX + 32 >> 3) >> 1, (player->posY + 32 >> 3) >> 1) == 0 && player->posX + 32 - (player->posX + 32 >> 3) >> 1 > 0) 
    {
        KLog("Collision !");
        playerSetCoordinates(player, ((player->posX >> 3) << 3), player->posY);
    }

    //Horizontal Collisions
    else if(MAP_getTile(colmap, (player->posX >> 3) >> 1, (player->posY >> 3) >> 1) == 0 && player->posY - (player->posY >> 3) >> 1 > 0) 
    {
        KLog("Collision !");
        playerSetCoordinates(player, player->posX, ((player->posY >> 3) << 3) + 8);
    }

    else if(MAP_getTile(colmap, (player->posX + 32 >> 3) >> 1, (player->posY + 32 >> 3) >> 1) == 0 && player->posY + 32 - (player->posY + 32 >> 3) >> 1 > 0) 
    {
        KLog("Collision !");
        playerSetCoordinates(player, player->posX, ((player->posY >> 3) << 3));
    }

    player->velX = 0;
    player->velY = 0;
    
    
}