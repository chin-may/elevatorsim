#include "floor.h"
#include "elevator.h"
#include "state.h"
#include "consts.h"
#include "elevator_state.h"
#include "observer.h"
#include <cstdio>
#include "move_observer.h"
#include "line_observer.h"
#include "entry_observer.h"
#include <list>
using namespace std;

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
    observers = new list<observer*>;
    observers->push_back(new move_observer);
    observers->push_back(new entry_observer);
    observers->push_back(new line_observer);
    //srand(time(NULL));
}

void elevator_state::notify(list<event*> *events, event* prev, int type){
    for(list<observer*>::iterator it = observers->begin(); it!=observers->end();
            it++){
        (*it)->notify(this, events, prev, type);
    }
}

