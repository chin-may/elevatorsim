#ifndef ELEVATOR_STATE_H
#define ELEVATOR_STATE_H

#include "floor.h"
#include "elevator.h"

class elevator_state::state{
    int currid;
    floor* level[FLOORNUM];
    elevator* elev[ELEVATORNUM];

    public:
    elevator_state();
};

elevator_state::elevator_state(){
    currid = 0;
    for(int i = 0; i < FLOORNUM; i++){
        level[i] = new floor;
    }
    for(int i = 0; i < ELEVATORNUM; i++){
        elev[i] = new elevator;
    }
}
#endif
