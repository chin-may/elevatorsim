#ifndef ENTER_EVENT_H
#define ENTER_EVENT_H

#include "event.h"

class alight_event::event{
    int elevid;
    alight_event(int id){
        elevid = id;
    }
    void happen(elevator_state *st){
        elevator *e = st->elev[elevid];
        floor *f = st->level[e->location];
        Queue *q= e->leave();
        if(e->location > 0){
            Person* p = 0;
            int success;
            while(p = q->deque()){
                success = f->enter(p);
                if(!success){
                    p->dest = 0;
                    f->down->enque(p);
                }
            }

        }
    }
};

#endif
