#include "scheduler.h"
#include "event.h"

void scheduler::run(){
    while(true){
        event *e = events.front();
        events.pop_front();
        e->happen(system, events);
        st->show();
    }
}

scheduler::scheduler(state *st){
    events = new list<event>;
    system = st;
}
