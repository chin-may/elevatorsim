#include <stdlib.h>
#include "elevator.h"
#include "consts.h"
#include "queue.h"
#include "Person.h"

elevator* elevator_new(){
    elevator* ret = malloc(sizeof(elevator));
    int i;
    for(i = 0; i < ELEVATOR_CAP; i++){
        ret->passengers[i] = 0;
    }
    ret->pnum = 0;
    ret->location = 0;
    ret->delay = 0;
    for(i = 0; i< FLOORNUM; i++){
        ret->dest[i] = 0;
        ret->ext_dest[i] = 0;
    }
    return ret;
}

void elevator_move(elevator* e){
    if(e->delay){
        e->delay--;
    }
    else{
        e->location += e->moving;
    }
}



void elevator_pause(elevator* e, int time){
    e->delay = time;
    //int i;
    //e->dest[e->location]  = 0;
}

int elevator_isfree(elevator* e){
    int i;
    for(i = 0; i < FLOORNUM; i++){
        if(elevator_hasdest(e,i) != 0){
            return 0;
        }
    }
    return 1;
}


void elevator_setdir(elevator* e){
    int i;
    int has_up = 0, has_down = 0;
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(e->passengers[i] != NULL){
            if(e->passengers[i]->dest > e->location){
                has_up = 1;
            }
            else if(e->passengers[i]->dest < e->location){
                has_down = 1;
            }
        }
    }
    if(e->moving == 0){
        if(has_up) e->moving = 1;
        else if(has_down) e->moving = -1;
    }
    else if(e->moving == 1){
        if(has_up) e->moving = 1;
        else if(has_down) e->moving = -1;
        else e->moving = 0;
    }
    else{
        if(has_down) e->moving = -1;
        else if(has_up) e->moving = 1;
        else e->moving = 0;
    }
}


void elevator_setdest(elevator* e){
    int i;
    for(i = 0; i < FLOORNUM; i++){
        e->dest[i] = 0;
    }
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(e->passengers[i] != NULL){
            e->dest[e->passengers[i]->dest] = 1;
        }
    }
}


void elevator_enter(elevator* e, Person* p){
    if(e->pnum == ELEVATOR_CAP){
        perror("Elevator overload");
        exit(1);
    }
    int i = 0;
    while(e->passengers[i] != NULL){
        i++;
    }
    e->passengers[i] = p;
    e->pnum++;
}


Queue* elevator_leave(elevator* e){
    int i;
    Queue* q = queue_new();
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(e->passengers[i] != NULL){
            if(e->passengers[i]->dest == e->location){
                queue_enque(q, e->passengers[i]);
                e->passengers[i] = NULL;
                e->pnum--;
            }

        }
    }
    return q;
}

int elevator_atdest(elevator* e){
    return e->dest[e->location];
}

int elevator_hasdest(elevator* e, int d){
    if(d>= 0 && d< FLOORNUM)
        return e->dest[d] || e->ext_dest[d];
}

int elevator_hasfurther(elevator* e){
    int ret = 0;
    int i;
    if(e->moving > 0){
        i = e->location + 1;
        while(i < FLOORNUM){
            if(elevator_hasdest(e,i)) return 1;
            i++;
        }
        return 0;
    }
    else if(e->moving < 0){
        i = e->location - 1;
        while(i >= 0){
            if(elevator_hasdest(e,i)) return 1;
            i--;
        }
        return 0;
    }
    return 0;
}

void elevator_print(elevator* e){
    printf("Elevator loc:%d\n", e->location);
    if(e->delay > 0){
        printf("Delay: %d\n", e->delay);
    }
    int i;
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(e->passengers[i]!=NULL){
            printf("p%d dest: %d,", e->passengers[i]->id, e->passengers[i]->dest);
        }
    }
    printf("\n");
}
