#include <stdlib.h>
#include <stdio.h>
#include "floor.h"

floor::floor(int num){
    up = new Queue;
    down = new Queue;
    memnum = 0;
    int i;
    for(i = 0; i < FLOOR_CAP; i++){
        members[i] = NULL;
    }
}

int floor::enter(Person* p){
    if(memnum == FLOOR_CAP){
        return 0;
    }
    int i = 0;
    while(members[i] != NULL){
        i++;
    }
    members[i] = p;
    memnum++;
    return 1;
}

void floor::print(){
    printf("Inside:\n");
    int i = 0;
    for(i = 0; i < FLOOR_CAP; i++){
        if(members[i] != NULL){
            printf("p%d ", members[i]->id);
        }
    }
    printf("\nUp Queue:\n");
    Node* n;
    n = up->head;
    for(i = 0; i < up->length; i++){
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\nDown Queue:\n");
    n = down->head;
    for(i = 0; i < down->length; i++){
        printf("p%d dest %d, ", n->data->id, n->data->dest);
        n = n->next;
    }
    printf("\n");
}
