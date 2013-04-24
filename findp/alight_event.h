#ifndef ALIGHT_EVENT_H
#define ALIGHT_EVENT_H

#include <list>
#include "event.h"

class alight_event: public event{
    public:
    int elevid;
    alight_event(int id){
        elevid = id;
    }
    void happen(state *st_, std::list<event*> *events);
};

#endif
