#include "line_observer.h"
#include "elevator_state.h"
#include "line_event.h"
#include "event.h"
#include <list>
using namespace std;
void line_observer::notify(state* st_, list<event*>* events, event* prev, 
        int type){
    elevator_state *st = (elevator_state*) st_;
    if(type==1){
        line_event * le = (line_event*) prev;
        events->push_back(new line_event(le->floorid));
    }
}
