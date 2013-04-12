#include "scheduler.h"
#include "state.h"
#include "elevator_state.h"
#include "consts.h"
#include "new_entry_event.h"
#include "enter_event.h"
#include "move_event.h"

void initialize(elevator_state *st, scheduler *sch);

int main(){
    elevator_state *st = new elevator_state;
    scheduler *sch = new scheduler(st);
    initialize(st, sch);
    sch->run();
    return 0;
}

void initialize(elevator_state *st, scheduler *sch){
    st->events->push_back(new new_entry_event);
    for(int i = 0; i<FLOORNUM; i++){
        st->events->push_back(new line_event(i));
    }
    for(int i = 0; i<ELEVATORNUM; i++){
        st->events->push_back(new enter_event(i));
        st->events->push_back(new move_event(i));
    }
}
