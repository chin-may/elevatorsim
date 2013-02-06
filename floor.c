#include "floor.h"

floor floor_new(int num){
    floor *ret = malloc(sizeof(floor));
    ret->up = queue_new();
    ret->down = queue_new();
    ret->memnum = 0;
    int i;
    for(i = 0; i < FLOOR_CAP; i++){
        ret->members[i] = NULL;
    }
}
