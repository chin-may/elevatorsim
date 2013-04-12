#ifndef ENTER_EVENT_H
#define ENTER_EVENT_H

#include "event.h"
class new_entry_event::event{
    void happen(elevator_state *st){
        int num = rand()%(MAX_ENT + 1);
        int i;
        Person* p;
        for(i = 0; i < num; i++){
            p = new Person(++(st->currid));
            p->dest = random()%(FLOORNUM - 1) + 1;
            st->floor[0]->up->enque(p);
        }
    }
}

#endif
