#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "event.h"
#include "state.h"
using namespace std;

class scheduler{
    list<Event> *events;
    state *system;
    void run(state *system);
};

#endif
