#include <stdlib.h>
#include "floor.h"

floor* floor_new(int num){
    floor *ret = malloc(sizeof(floor));
    ret->up = queue_new();
    ret->down = queue_new();
    ret->memnum = 0;
    int i;
    for(i = 0; i < FLOOR_CAP; i++){
        ret->members[i] = NULL;
    }
    return ret;
}

void floor_enter(floor* f, Person* p){
    if(f->memnum == FLOOR_CAP){
        perror("Floor full");
        exit(1);
    }
    int i;
    while(f->members[i] != NULL){
        i++;
    }
    f->members[i] = p;
    f->memnum++;

}
