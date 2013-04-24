#ifndef STATE_H
#define STATE_H
class state;
class event;
#include "event.h"
#include <list>
class state{
    public:
        virtual void show() = 0;
        void notify(std::list<event*> *events, event* prev,int type);

};
#endif
