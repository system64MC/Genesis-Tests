#include <genesis.h>
#include "init.h"
#include "joy.h"

void init()
{
    SPR_init(0, 0, 0);
    VDP_setTextPlane(BG_A);
    JOY_init();
}