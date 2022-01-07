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

    int tempX = player->posX + player->velX;



    /*
    // en x
    si collision à à x+8, x+24 (y = 0) et à y = 32
        faireLaCorrection()
    else
   j    eVérifieEntre() // points verts

    // en y
    si collision à x+8 et y+1 et idem à y = 31
        faireLaCorrection()
    else
        jeVérifieEntre() // points rouges
    */

   //X Collisions
    if(MAP_getTile(colmap, (tempX + 8 >> 3) >> 1, (player->posY + 1 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);

    }
    else if(MAP_getTile(colmap, (tempX + 24 >> 3) >> 1, (player->posY + 1 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }
    else if(MAP_getTile(colmap, (tempX + 8 >> 3) >> 1, (player->posY + 31 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }
    else if(MAP_getTile(colmap, (tempX + 24 >> 3) >> 1, (player->posY + 31 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }

    // Checking between the edges
    else if(MAP_getTile(colmap, (tempX + 8 >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0)
    {
        /* code de correction*/
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }
    }
    else if(MAP_getTile(colmap, (tempX + 24 >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0)
    {
        /* code de correction*/
        KLog("Collision !");
        
        if(player->velX > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempX & 7;
            player->velX -= correct;
        }
        else if(player->velX < 0)
        {
            int correct = tempX & 7;
            player->velX += correct;
        }
    }


    int tempY = player->posY + player->velY;

//Y Collisions
    if(MAP_getTile(colmap, (player->posX + 8 >> 3) >> 1, (tempY >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velY > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempY & 7;
            player->velY -= correct;
        }
        else if(player->velY < 0)
        {
            int correct = tempY & 7;
            player->velY += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);

    }
    else if(MAP_getTile(colmap, (player->posX + 24 >> 3) >> 1, (tempY >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velY > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempY & 7;
            player->velY -= correct;
        }
        else if(player->velY < 0)
        {
            int correct = tempY & 7;
            player->velY += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }
    else if(MAP_getTile(colmap, (player->posX + 8 >> 3) >> 1, (tempY + 32 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velY > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempY & 7;
            player->velY -= correct;
        }
        else if(player->velY < 0)
        {
            int correct = tempY & 7;
            player->velY += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }
    else if(MAP_getTile(colmap, (player->posX + 24 >> 3) >> 1, (tempY + 32 >> 3) >> 1) == 0) 
    {
        KLog("Collision !");
        
        if(player->velY > 0)
        {
            // int dest = player->posX + player->velX;
            int correct = tempY & 7;
            player->velY -= correct;
        }
        else if(player->velY < 0)
        {
            int correct = tempY & 7;
            player->velY += correct;
        }

        //playerSetCoordinates(player, ((player->posX >> 3) << 3) + 8, player->posY);
    }

    // // Checking between the edges
    // else if(MAP_getTile(colmap, (tempX + 8 >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0)
    // {
    //     /* code de correction*/
    //     KLog("Collision !");
        
    //     if(player->velX > 0)
    //     {
    //         // int dest = player->posX + player->velX;
    //         int correct = tempX & 7;
    //         player->velX -= correct;
    //     }
    //     else if(player->velX < 0)
    //     {
    //         int correct = tempX & 7;
    //         player->velX += correct;
    //     }
    // }
    // else if(MAP_getTile(colmap, (tempX + 24 >> 3) >> 1, (player->posY + 16 >> 3) >> 1) == 0)
    // {
    //     /* code de correction*/
    //     KLog("Collision !");
        
    //     if(player->velX > 0)
    //     {
    //         // int dest = player->posX + player->velX;
    //         int correct = tempX & 7;
    //         player->velX -= correct;
    //     }
    //     else if(player->velX < 0)
    //     {
    //         int correct = tempX & 7;
    //         player->velX += correct;
    //     }
    // }


    playerSetCoordinates(player, player->posX + player->velX, player->posY + player->velY);

    player->velX = 0;
    player->velY = 0;
    
    
}