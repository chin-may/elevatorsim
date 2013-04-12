#ifndef LINE_EVENT_H
#define LINE_EVENT_H

#include "event.h"

class line_event::event{
    int floorid;
    line_event(int id){
        floorid = id;
    }
    void happen(elevator_state *st){
        floor *f = st->level[floorid];
        int i;
        int chance;
        int dest;
        if(floorid > 0){
            for(i = 0; i < FLOOR_CAP; i++){
                if(f->members[i] != NULL){
                    chance = random() % 4;
                    if(chance == 0){
                        dest = random()%FLOORNUM;
                        if(dest != floorid){
                            f->members[i]->dest = dest;
                            if(dest > floorid){
                                queue_enque(f->up, f->members[i]);
                            }
                            else{
                                queue_enque(f->down, f->members[i]);
                            }
                            f->members[i] = NULL;
                            f->memnum--;
                        }
                    }
                }
            }
        }
        if(f->up->length > 0 || f->down->length > 0){
            int already_set = 0;
            int has_elev = 0;
            int i;
            for(i = 0; i < ELEVATORNUM; i++){
                if(elev[i]->hasdest(floorid) ){
                    already_set = 1;
                }
                if(elev[i]->location == floorid){
                    has_elev = 1;
                }
            }
            if(!already_set && !has_elev){
                int choice = random() % ELEVATORNUM;
                elev[choice]->ext_dest[floorid] = 1;
            }
        }

    }
};

#endif
