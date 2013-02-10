#include <stdlib.h>
#include <stdio.h>
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

int floor_enter(floor* f, Person* p){
    if(f->memnum == FLOOR_CAP){
        return 0;
    }
    int i = 0;
    while(f->members[i] != NULL){
        i++;
    }
    f->members[i] = p;
    f->memnum++;
    return 1;
}

void floor_print(floor* f){
    printf("Inside:\n");
    int i = 0;
    for(i = 0; i < FLOOR_CAP; i++){
        if(f->members[i] != NULL){
            printf("p%d ", f->members[i]->id);
        }
    }
    printf("\nUp Queue:\n");
    Node* n;
    n = f->up->head;
    for(i = 0; i < f->up->length; i++){
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\nDown Queue:\n");
    n = f->down->head;
    for(i = 0; i < f->down->length; i++){
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\n");
}
