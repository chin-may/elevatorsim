#ifndef EVENT_H
#define EVENT_H
#include "state.h"
#include <list>
using namespace std;

class event{
    public:
    //TODO What happens if I remove this virtual?
    virtual void happen(state *system, list<event*> *events) = 0;
};

#endif
