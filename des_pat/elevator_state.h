#ifndef ELEVATOR_STATE_H
#define ELEVATOR_STATE_H

#include "floor.h"
#include "elevator.h"
#include "state.h"
#include "consts.h"
#include <cstdio>

class elevator_state: public state{
    public:
    int currid; //Number of people the system has seen till now
    floor* level[FLOORNUM];
    elevator* elev[ELEVATORNUM];
    elevator_state();
    void show(){
        int i;
        for(i = 0; i< FLOORNUM; i++){
            printf("Floor %d\n",i);
            level[i]->print();
        }
        for(i = 0; i < ELEVATORNUM; i++){
            printf("\nElevator %d\n",i);
            elev[i]->print();
        }

    }
};

elevator_state::elevator_state(){
    currid = 0;
    for(int i = 0; i < FLOORNUM; i++){
        level[i] = new floor(i);
    }
    for(int i = 0; i < ELEVATORNUM; i++){
        elev[i] = new elevator;
    }
    //srand(time(NULL));
}
#endif
