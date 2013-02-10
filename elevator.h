#include "consts.h"
#ifndef ELEVATOR_H

#define ELEVATOR_H
#define ELEVATOR_CAP 8
#define ELEVATOR_DELAY 3

typedef struct elevator_ elevator;
struct elevator_{
    Person* passengers[ELEVATOR_CAP];
    int pnum;
    int location;
    int delay;
    int moving;
    //int free;
    int dest[FLOORNUM];
    int ext_dest[FLOORNUM];
};

elevator* elevator_new();

void elevator_move(elevator* e);

//void elevator_stop(elevator* e);
//
void elevator_pause(elevator* e, int time);

int elevator_isfree(elevator* e);

void elevator_setdir(elevator* e);

void elevator_setdest(elevator* e);

void elevator_enter(elevator* e, Person* p);

Queue* elevator_leave(elevator* e);

//Checks if e has any further targets in the same direction as it is moving
int elevator_hasfurther(elevator* e);
#endif
