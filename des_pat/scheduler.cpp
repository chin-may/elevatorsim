#include "scheduler.h"
#include "event.h"
#include "state.h"

void scheduler::run(){
    while(true){
        event *ev = events->front();
        events->pop_front();
        ev->happen(system, events);
        system->show();
    }
}

scheduler::scheduler(state *st){
    events = new list<event*>;
    system = st;
}
