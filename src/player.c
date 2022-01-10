#include<genesis.h>
#include "actor.h"
#include "player.h"
#include "sprites.h"
#include "playfield.h"
#include "collision.h"
#include "utils.h"
// #include <psg.h>

// Move the player

// inits the player at xy coordinates and returns a pointer to the player struct
s8 grav = 8;
s8 gravcheck = 0;

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
    // if(player->velX != 0 || player->velY != 0)
    // {
    //     playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);
    // }
        // player->velY = 0;
    
        if(JoyDown(BUTTON_RIGHT))
        {
            player->velX = 4;
        }
        if(JoyDown(BUTTON_LEFT))
        {
            player->velX = -4;
        } 
        if(JoyDown(BUTTON_UP))
        {
            player->velY -= grav;
        } 

        if(JoyDown(BUTTON_A) && gravcheck == 0)
        {
            grav *= -1;
	    gravcheck = 1;
        }
	if(!JoyDown(BUTTON_A))
        {
	    gravcheck = 0;
        }

    // if(player, player->velX != 0 || player->velY != 0)
    // {
    //     playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);
    // }

    // calcul de la boite de collision

    s16 x1 = player->posX + 8, y1 = player->posY + 4;
    s16 x2 = player->posX + 24, y2 = player->posY + 31;
    
    // calcul des positions de tests
    const s16 hTests[3] = {y1, y2-1, y1 + 16};
    const s16 vTests[2] = {x1, x2-1};

    s16 correct = 0;

    if(player->velX > 0) {
        correct = getCollisionPosX(x2 + player->velX, hTests, 3);
        player->velX -= correct;
    } else if(player->velX < 0) {
        correct = getCollisionPosX(x1 + player->velX, hTests, 3);  
        player->velX += (16 - correct)&0xF;
    }

    if(player->velY > 0) {
        // le 3ieme paramètres jte l'ai écrit différemment, c'est un méthode safe... c'est possible d'en faire une macro qui se nommerait len(...)
        correct = getCollisionPosY(vTests, y2 + player->velY, (sizeof(vTests)/sizeof(__typeof__(*vTests))));
        player->velY -= correct;
    } else if(player->velY < 0) {
        correct = getCollisionPosY(vTests, y1 + player->velY, 2);  
        player->velY += (16 - correct)&0xF;
    }

    if(player, player->velX != 0 || player->velY != 0)
    {
        playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);
    }

    player->velX = 0;
    player->velY = grav;
    
    
}

s16 getCollisionPosX(s16 x, s16* ys, u16 array_size) {
    s16 tx = x>>4;
    while(array_size > 0) {
        array_size--;
        if(MAP_getTile(colmap, tx, *ys>>4) == 0) {
            return x & 15;
        }
        ys++;
    }
    return 0;
}

s16 getCollisionPosY(s16* xs, s16 y, u16 array_size) {
    s16 ty = y>>4;
    while(array_size > 0) {
        array_size--;
        if(MAP_getTile(colmap, *xs>>4, ty) == 0) {
            return y & 15;
        }
        xs++;
    }
    return 0;
}