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

void floor_enter(floor* f, Person* p){
    if(f->memnum == FLOOR_CAP){
        perror("Floor full");
        exit(1);
    }
    int i = 0;
    while(f->members[i] != NULL){
        i++;
    }
    f->members[i] = p;
    f->memnum++;

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
    for(i = 0; i < f->up->length; i++){
        n = f->up->head;
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\nDown Queue:\n");
    for(i = 0; i < f->down->length; i++){
        n = f->down->head;
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\n");
}
