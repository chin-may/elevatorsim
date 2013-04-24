#ifndef MOVE_EVENT_H
#define MOVE_EVENT_H

#include "event.h"
#include "consts.h"

class move_event: public event{
    public:
    int elevid;
    move_event(int id){
        elevid = id;
    }
    void happen(state *st_, std::list<event*> *events);
};

#endif
