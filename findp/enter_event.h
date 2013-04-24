#ifndef ENTER_EVENT_H
#define ENTER_EVENT_H

#include "event.h"
#include "consts.h"
#include "Person.h"
class enter_event: public event{
    public:
    int elevid;
    enter_event(int id){
        elevid = id;
    }
    void happen(state *st_,std::list<event*> *events);

};

#endif
