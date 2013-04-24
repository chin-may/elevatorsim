#include "consts.h"
#include "Person.h"
#include "queue.h"
#ifndef ELEVATOR_H

#define ELEVATOR_H
#define ELEVATOR_CAP 8
#define ELEVATOR_DELAY 3

class elevator{
    public:
        Person* passengers[ELEVATOR_CAP];
        int pnum;
        int location;
        int delay;
        int moving;
        //int free;
        int dest[FLOORNUM];
        int ext_dest[FLOORNUM];
        bool just_stopped;
        elevator();

        void move();

        //void elevator_stop(elevator* e);
        //
        void pause(int time);

        int isfree();

        void setdir();
        void setdir_ext();

        void setdest();

        int hasdest(int d);
        int atdest();

        void enter(Person* p);

        Queue* leave();

        //Checks if e has any further targets in the same direction as it is moving
        int hasfurther();

        void print();
};

#endif
