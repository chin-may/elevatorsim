#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include "event.h"
#include "state.h"

class scheduler{
    public:
        std::list<event*> *events;
        state *system;
        void run();
        scheduler(state *st);
};

#endif
