#ifndef MOVEOBSERVER_H
#define MOVEOBSERVER_H

#include "event.h"
#include "state.h"
#include "observer.h"
#include <list>

class move_observer: public observer{
    public:
        void notify(state* st_, std::list<event*>* events, event* prev, int type);
};


#endif
