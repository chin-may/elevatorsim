#ifndef LINEOBSERVER_H
#define LINEOBSERVER_H

#include "event.h"
#include "state.h"
#include "observer.h"

class entry_observer: public observer{
    public:
        void notify(state* st_, std::list<event*>* events, event* prev, int type);
};


#endif
