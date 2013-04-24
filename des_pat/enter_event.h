#ifndef ENTER_EVENT_H
#define ENTER_EVENT_H

#include "event.h"
#include "consts.h"
#include "Person.h"
class enter_event: public event{
    public:
    int elevid;
    enter_event(int id){
        elevid = id;
    }
    void happen(state *st_,list<event*> *events){
        elevator_state *st = (elevator_state*) st_;
        elevator *e = st->elev[elevid];
        floor *currentfloor = st->level[st->elev[elevid]->location];
        Person *p;
        if(e->moving != 0 && e->just_stopped){
            e->just_stopped = false;
            if(e->hasfurther()){
                if(e->moving > 0){
                    while(e->pnum < ELEVATOR_CAP && 
                            currentfloor->up->length > 0){
                        p = currentfloor->up->deque();
                        e->enter(p);
                    }
                }
                else if(e->moving < 0){
                    while(e->pnum < ELEVATOR_CAP && 
                            currentfloor->down->length > 0){
                        p = currentfloor->down->deque();
                        e->enter(p);
                    }
                }
                e->setdest();
            }
            else{
                if(currentfloor->up->length == 0 && 
                        currentfloor->down->length == 0){
                    e->setdir_ext();
                }
                else if(currentfloor->up->length > 
                        currentfloor->down->length){
                    while(e->pnum < ELEVATOR_CAP && 
                            currentfloor->up->length > 0){
                        p = currentfloor->up->deque();
                        e->enter(p);
                    }
                    e->moving = 1;
                }
                else {
                    while(e->pnum < ELEVATOR_CAP && 
                            currentfloor->down->length > 0){
                        p = currentfloor->down->deque();
                        e->enter(p);
                    }
                    e->moving = -1;
                }
                e->setdest();
            }
        }
        if(e->moving == 0){
            Person* p;
            if(currentfloor->up->length == 0 && 
                    currentfloor->down->length == 0){
                e->setdir_ext();
            }
            else if(currentfloor->up->length > currentfloor->down->length){
                while(e->pnum < ELEVATOR_CAP && currentfloor->up->length > 0){
                    p = currentfloor->up->deque();
                    e->enter(p);
                }
                e->moving = 1;
            }
            else {
                while(e->pnum < ELEVATOR_CAP && 
                        currentfloor->down->length > 0){
                    p = currentfloor->down->deque();
                    e->enter(p);
                }
                e->moving = -1;
            }
            e->setdest();
        }
    }

};

#endif
