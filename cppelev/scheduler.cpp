#include "scheduler.h"

void scheduler::run(){
    while(true){
        event *e = events.front();
        events.pop_front();
        e->happen(system, events);
    }
}
