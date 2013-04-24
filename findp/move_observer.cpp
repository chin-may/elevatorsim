#include "move_observer.h"
#include "event.h"
#include "alight_event.h"
#include "enter_event.h"
#include "move_event.h"
#include "state.h"
#include "elevator_state.h"

#include <list>

using namespace std;
void move_observer::notify(state* st_, list<event*>* events, event* prev, 
        int type){
    elevator_state *st = (elevator_state*) st_;
    if(type==0){
        move_event * me = (move_event*) prev;
        events->push_back(new alight_event(me->elevid));
        events->push_back(new enter_event(me->elevid));
        events->push_back(new move_event(me->elevid));
    }
}
