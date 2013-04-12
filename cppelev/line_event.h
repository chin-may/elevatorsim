#ifndef LINE_EVENT_H
#define LINE_EVENT_H

#include "event.h"
#include "consts.h"

class line_event: public event{
    public:
    int floorid;
    line_event(int id){
        floorid = id;
    }
    void happen(state *st_, list<event*> *events){
        elevator_state *st = (elevator_state*) st_;
        floor *f = st->level[floorid];
        int i;
        int chance;
        int dest;
        if(floorid == 0) printf("Error line event on ground floor\n");
        for(i = 0; i < FLOOR_CAP; i++){
            if(f->members[i] != NULL){
                chance = random() % 4;
                if(chance == 0){
                    dest = random()%FLOORNUM;
                    if(dest != floorid){
                        f->members[i]->dest = dest;
                        if(dest > floorid){
                            f->up->enque( f->members[i]);
                        }
                        else{
                            f->down->enque(f->members[i]);
                        }
                        f->members[i] = NULL;
                        f->memnum--;
                    }
                }
            }
        }
        if(f->up->length > 0 || f->down->length > 0){
            int already_set = 0;
            int has_elev = 0;
            int i;
            for(i = 0; i < ELEVATORNUM; i++){
                if(st->elev[i]->hasdest(floorid) ){
                    already_set = 1;
                }
                if(st->elev[i]->location == floorid){
                    has_elev = 1;
                }
            }
            if(!already_set && !has_elev){
                int choice = random() % ELEVATORNUM;
                st->elev[choice]->ext_dest[floorid] = 1;
            }
        }
        events->push_back(new line_event(floorid));
    }

};

#endif
