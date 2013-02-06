#include "floor.h"

floor floor_new(){
    floor *ret = malloc(sizeof(floor));
    ret->up = queue_new();
    ret->down = queue_new();
}
