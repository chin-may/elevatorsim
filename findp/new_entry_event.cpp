#include "new_entry_event.h"
#include "event.h"
#include "consts.h"
#include <cstdlib>
#include <list>
#include "elevator_state.h"

using namespace std;
void new_entry_event::happen(state *st_, list<event*> *events) {
    elevator_state *st = (elevator_state*) st_;
    int num = random()%(MAX_ENT + 1);
    int i;
    Person* p;
    floor *f = st->level[0];
    for(i = 0; i < num; i++){
        p = new Person(++(st->currid));
        p->dest = random()%(FLOORNUM - 1) + 1;
        st->level[0]->up->enque(p);
    }
    if(f->up->length > 0 || f->down->length > 0){
        int already_set = 0;
        int has_elev = 0;
        int i;
        for(i = 0; i < ELEVATORNUM; i++){
            if(st->elev[i]->hasdest(0) ){
                already_set = 1;
            }
            if(st->elev[i]->location == 0){
                has_elev = 1;
            }
        }
        if(!already_set && !has_elev){
            int choice = random() % ELEVATORNUM;
            st->elev[choice]->ext_dest[0] = 1;
        }
    }
    st->notify(events, this, 2);
}
