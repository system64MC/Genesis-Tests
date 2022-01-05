#include <genesis.h>

bool isTileSolid(int x1, int y1, int x2, int y2, Map* colmap)
{
    return(MAP_getTile(colmap, (x1 >> 3) >> 1, (y1 >> 3) >> 1) == 0 || MAP_getTile(colmap, (x2 >> 3) >> 1, (y2 >> 3) >> 1) == 0);
}