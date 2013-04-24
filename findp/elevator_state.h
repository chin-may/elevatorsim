#ifndef ELEVATOR_STATE_H
#define ELEVATOR_STATE_H

#include "floor.h"
#include "elevator.h"
#include "state.h"
#include "consts.h"
#include "elevator_state.h"

class elevator_state: public state{
    public:
    int currid; //Number of people the system has seen till now
    floor* level[FLOORNUM];
    elevator* elev[ELEVATORNUM];
    elevator_state();
    void show();
};
#endif
