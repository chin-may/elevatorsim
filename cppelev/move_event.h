#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#include "event.h"
#include "consts.h"
#include "enter_event.h"
#include "move_event.h"
#include "alight_event.h"

class move_event::event{
    int elevid;
    move_event(int id){
        elevid = id;
    }
    void happen(elevator_state *st, list<event> *events){
        elevator *e = st->elev[elevid];
        e->move();
        if(e->moving != 0 && e->atdest()){ 
            e->pause(random() % (MAX_WAIT - 2) + 2); //Also clears target
        }
        alight_event *ae = new alight_event(elevid);
        enter_event *ee = new enter_event(elevid);
        move_event *me = new move_event(elevid);
        events.push_back(ae);
        events.push_back(ee);
        events.push_back(me);
    }

#endif
