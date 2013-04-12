#ifndef NEW_ENTRY_EVENT_H
#define NEW_ENTRY_EVENT_H

#include "event.h"
#include "consts.h"
class new_entry_event::event{
    void happen(elevator_state *st, list<event> *events){
        int num = rand()%(MAX_ENT + 1);
        int i;
        Person* p;
        floor *f = st->level[0];
        for(i = 0; i < num; i++){
            p = new Person(++(st->currid));
            p->dest = random()%(FLOORNUM - 1) + 1;
            st->floor[0]->up->enque(p);
        }
        if(f->up->length > 0 || f->down->length > 0){
            int already_set = 0;
            int has_elev = 0;
            int i;
            for(i = 0; i < ELEVATORNUM; i++){
                if(elevator_hasdest(elev[i],fnum) ){
                    already_set = 1;
                }
                if(elev[i]->location == fnum){
                    has_elev = 1;
                }
            }
            if(!already_set && !has_elev){
                int choice = random() % ELEVATORNUM;
                elev[choice]->ext_dest[fnum] = 1;
            }
        }
        events.push_back(new new_entry_event);
    }
}

#endif
