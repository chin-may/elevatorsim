#ifndef OBSERVER_H
#define OBSERVER_H

#include "event.h"
#include "state.h"
#include <list>

class observer{
    public:
        virtual void notify(state* st, std::list<event*>* events, event* prev, int type)=0;
};


#endif
