#include <stdlib.h>
#include <stdio.h>
#include "elevator.h"
#include "consts.h"
#include "queue.h"
#include "Person.h"

elevator(){
    int i;
    for(i = 0; i < ELEVATOR_CAP; i++){
        passengers[i] = 0;
    }
    pnum = 0;
    location = 0;
    delay = 0;
    for(i = 0; i< FLOORNUM; i++){
        dest[i] = 0;
        ext_dest[i] = 0;
    }
}

void move(){
    if(delay){
        delay--;
    }
    else{
        location += moving;
    }
}



void pause( int time){
    delay = time;
    dest[location] = 0;
    ext_dest[location] = 0;
    //int i;
}

int isfree(){
    int i;
    for(i = 0; i < FLOORNUM; i++){
        if(elevator_hasdest(e,i) != 0){
            return 0;
        }
    }
    return 1;
}


void setdir(){
    int i;
    int has_up = 0, has_down = 0;
    for(i = 0; i < CAP; i++){
        if(passengers[i] != NULL){
            if(passengers[i]->dest > location){
                has_up = 1;
            }
            else if(passengers[i]->dest < location){
                has_down = 1;
            }
        }
    }
    if(moving == 0){
        if(has_up) moving = 1;
        else if(has_down) moving = -1;
    }
    else if(moving == 1){
        if(has_up) moving = 1;
        else if(has_down) moving = -1;
        else moving = 0;
    }
    else{
        if(has_down) moving = -1;
        else if(has_up) moving = 1;
        else moving = 0;
    }
}


void setdir_ext(){
    int i;
    int has_up = 0, has_down = 0;
    i = location + 1;
    while(i < FLOORNUM){
        if(ext_dest[i]){
            has_up = 1;
        }
        i++;
    }
    i = location - 1;
    while(i >= 0){
        if(ext_dest[i]){
            has_down = 1;
        }
        i--;
    }
    if(has_down){
        moving = -1;
    }
    else if(has_up){
        moving = 1;
    }
    else {
        moving = 0;
    }
}


void setdest(){
    int i;
    for(i = 0; i < FLOORNUM; i++){
        dest[i] = 0;
    }
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(passengers[i] != NULL){
            dest[passengers[i]->dest] = 1;
        }
    }
}


void enter(Person* p){
    if(pnum == ELEVATOR_CAP){
        perror("Elevator overload");
        exit(1);
    }
    int i = 0;
    while(passengers[i] != NULL){
        i++;
    }
    passengers[i] = p;
    pnum++;
}


Queue* leave(){
    int i;
    Queue* q = new Queue;
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(passengers[i] != NULL){
            if(passengers[i]->dest == location){
                q->enque(passengers[i]);
                passengers[i] = NULL;
                pnum--;
            }

        }
    }
    return q;
}

int atdest(){
    return hasdest(location);
}

int hasdest(int d){
    if(d>= 0 && d< FLOORNUM)
        return dest[d] || ext_dest[d];
}

int hasfurther(){
    int ret = 0;
    int i;
    if(moving > 0){
        i = location + 1;
        while(i < FLOORNUM){
            if(hasdest(i)) return 1;
            i++;
        }
        return 0;
    }
    else if(moving < 0){
        i = location - 1;
        while(i >= 0){
            if(hasdest(i)) return 1;
            i--;
        }
        return 0;
    }
    return 0;
}

void print(){
    printf("Elevator loc:%d\n", location);
    if(delay > 0){
        printf("Delay: %d\n", delay);
    }
    int i;
    for(i = 0; i < ELEVATOR_CAP; i++){
        if(passengers[i]!=NULL){
            printf("p%d dest: %d,", passengers[i]->id, passengers[i]->dest);
        }
    }
    printf("\nTasks:\n");
    for(i = 0; i < FLOORNUM; i++){
        if(hasdest(i)){
            printf("%d, ",i);
        }
    }
    printf("\nMoving %d\n", moving);
}
