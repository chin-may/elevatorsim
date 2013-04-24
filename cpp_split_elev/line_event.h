#ifndef LINE_EVENT_H
#define LINE_EVENT_H

#include "event.h"
#include "consts.h"

class line_event: public event{
    public:
    int floorid;
    line_event(int id){
        floorid = id;
    }
    void happen(state *st_, std::list<event*> *events);

};

#endif
