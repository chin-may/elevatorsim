#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "event.h"
#include "state.h"
#include <list>
using namespace std;

class scheduler{
    public:
    list<event*> *events;
    state *system;
    void run();
    scheduler(state *st);
};

#endif
