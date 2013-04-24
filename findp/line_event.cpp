#include <cstdlib>
#include "line_event.h"
#include "event.h"
#include "consts.h"
#include "elevator_state.h"
using namespace std;
void line_event::happen(state *st_, list<event*> *events) {
        elevator_state *st = (elevator_state*) st_;
        floor *f = st->level[floorid];
        int i;
        int chance;
        int dest;
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
        st->notify(events, this, 1);
    }
