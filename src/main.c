/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include "init.h"
#include "player.h"
#include "actor.h"
#include "joy.h"
#include "update.h"
#include "sprites.h"
#include<kdebug.h>
#include "../res/map.h"
#include "playfield.h"
#include <psg.h>
#include "bullet.h"

Map* map;
int tileIndex = TILE_USERINDEX;

int main()
{
    // PSG_init();
    // PSG_setEnvelope(1, 0);
    // PSG_setFrequency(1, 10);
    
    KLog("TEST");
    init();
    VDP_loadTileSet(&testMapColTs, TILE_USERINDEX, DMA);
    VDP_loadTileSet(&testMapTs, TILE_USERINDEX + stars.tileset->numTile + testMapColTs.numTile, DMA);


    map = MAP_create(&testMap, BG_A, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_USERINDEX + stars.tileset->numTile + testMapColTs.numTile));
    colmap = MAP_create(&testMapCol, BG_B, NULL);
    MAP_scrollTo(map, 0, 0);
    // Actor* player = playerInit(50, 50);
    s16 bposX = 0;
    s16 bposY = 0;
    playerSetSprite(&player);
    playerSetCoordinates(&player, 50, 50);
    // VDP_draw
    
    VDP_loadTileSet(stars.tileset, TILE_USERINDEX + testMapColTs.numTile, DMA);
    VDP_setTileMapEx(BG_B, stars.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX + testMapColTs.numTile), 0, 64, 0, 0, 64, 32, DMA);
    // VDP_setTileMapEx(BG_B, stars.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX), 31, 31, 0, 0, 32, 32, DMA);
    //VDP_setTileMap(BG_B, stars.tilemap, 0, 0, 32, 32, DMA);
    //VDP_setTileMap(BG_B, stars.tilemap, 0, 32, 32, 32, DMA);
    //VDP_drawImageEx(BG_B, &stars, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, stars.palette->data, TRUE);
    //VDP_drawImageEx(BG_B, &stars, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX), 32, 0, stars.palette->data, TRUE);
    // VDP_drawImage(BG_B, &stars, 32, 0);
    // VDP_drawImage(BG_B, &stars, 0, 32);
    // VDP_drawImage(BG_B, &stars, 32, 32);
    VDP_setTextPlane(WINDOW);
    VDP_drawText("Hello Sega!!", 0,0);
    // VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);
    
    PAL_setPalette(PAL3, playerSpr.palette->data, DMA);
    PAL_setPalette(PAL1, testMap.palette->data, DMA);
    PAL_setPalette(PAL0, stars.palette->data, DMA);
    while(1)
    {
        JoyBegin();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SPR_update();
        
        
        update();
        JoyFinish();
        VDP_setVerticalScroll(BG_B, bposY);
        VDP_setHorizontalScroll(BG_B, bposX);
        bposX--;
        bposY++;
        if(bposX <= -512)
            bposX = 0;
        if(bposY >= 512)
            bposY = 0;
        SYS_doVBlankProcess();
    }
    return (0);
}
