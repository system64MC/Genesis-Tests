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

int main()
{
    init();
    // Actor* player = playerInit(50, 50);
    playerSetSprite(&player);
    playerSetCoordinates(&player, 50, 50);
    VDP_drawText("Hello Sega!!", 10,13);
    PAL_setPalette(PAL0, playerSpr.palette->data, DMA);
    while(1)
    {
        JoyBegin();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SPR_update();
        update();
        SYS_doVBlankProcess();
        JoyFinish();
    }
    return (0);
}
