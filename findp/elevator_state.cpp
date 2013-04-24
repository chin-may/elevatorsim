#include "floor.h"
#include "elevator.h"
#include "state.h"
#include "consts.h"
#include "elevator_state.h"
#include <cstdio>

void elevator_state::show(){
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
