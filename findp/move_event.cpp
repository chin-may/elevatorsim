#include "move_event.h"
#include "event.h"
#include "consts.h"
#include "enter_event.h"
#include "alight_event.h"
#include "elevator_state.h"
#include <cstdlib>
#include <list>
using namespace std;

void move_event::happen(state *st_, list<event*> *events){
    elevator_state *st = (elevator_state*)  st_;
    elevator *e = st->elev[elevid];
    e->move();
    if(e->moving != 0 && e->atdest()){ 
        e->pause(random() % (MAX_WAIT - 2) + 2); //Also clears target
        e->just_stopped = true;
    }
    st->notify(events, this, 0);
}
