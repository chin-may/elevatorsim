#include "entry_observer.h"
#include "event.h"
#include "elevator_state.h"
#include "new_entry_event.h"
#include <list>
using namespace std;

void entry_observer::notify(state* st_, list<event*>* events, event* prev, int type){
    elevator_state *st = (elevator_state*) st_;
    if(type==2){
        events->push_back(new new_entry_event);
    }
}
