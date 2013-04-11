#include "scheduler.h"

void scheduler::run(state system){
    while(true){
        event *e = events.front();
        events.pop_front();
        e->happen();
    }
}
