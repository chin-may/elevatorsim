#ifndef ALIGHT_EVENT_H
#define ALIGHT_EVENT_H

#include "event.h"

class alight_event: public event{
    public:
    int elevid;
    alight_event(int id){
        elevid = id;
    }
    void happen(state *st_, list<event*> *events){
        elevator_state *st = (elevator_state*) st_;
        elevator *e = st->elev[elevid];
        floor *f = st->level[e->location];
        if(e->moving != 0 && e->just_stopped){
            Queue *q= e->leave();
            if(e->location > 0){
                Person* p = 0;
                int success;
                while((p = q->deque())){
                    success = f->enter(p);
                    if(!success){
                        p->dest = 0;
                        f->down->enque(p);
                    }
                }

            }
        }
    }
};

#endif
