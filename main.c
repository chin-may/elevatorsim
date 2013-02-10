#include <stdio.h>
#include <stlib.h>
#include "queue.h"
#include "Person.h"
#include "floor.h"
#include "consts.h"


int main(){
    floor* level[FLOORNUM];
    int i;
    int currid = 1;
    for(i = 0; i < FLOORNUM; i++){
        level[i] = floor_new();
    }
    elevator* elev[ELEVATORNUM];
    for(i = 0; i < ELEVATORNUM; i++){
        elev[i] = elevator_new();
    }
    srand(time(NULL));

    int i;
    int currid = 1;
    while(1){
        currid = add_new_entrants(level[0], currid);
        for(i = 1; i < FLOORNUM; i++){
            update_queues(level[i], i);
            //TODO Add external task
        }
        for(i = 0; i < ELEVATORNUM; i++){
            elevator* e = elev[i];
            floor* currentfloor = level[ e->location/2 ];
            elevator_move(e);
            if(elevator_atdest(e)){ //TODO Check if SHOULD PAUSE
                elevator_pause(random() % (MAX_WAIT - 2) + 2);
                //TODO Clear target
                Person* p;
                Queue* q;
                q = elevator_leave(e);
                update_floor( currentfloor );
                if(e->moving > 0){
                    while(e->pnum < ELEVATOR_CAP && currentfloor->up->length > 0){
                        p = queue_deque(currentfloor->up);
                        elevator_enter(e, p);
                    }
                }
                else if(e->moving < 0){
                    while(e->pnum < ELEVATOR_CAP && currentfloor->down->length > 0){
                        p = queue_deque(currentfloor->down);
                        elevator_enter(e, p);
                    }

                }
            }
        }
    }

    return 0;
}


int add_new_entrants(floor* gr, int currid){
    int num = rand()%(MAX_ENT + 1);
    int i;
    Person* p
    for(i = 0; i < num; i++){
        p = person_new(++currid);
        p->dest = random()%(FLOORNUM - 1) + 1;
        queue_enque(f->up, p);
    }
    return currid;
}

void update_queues(floor* f, int fnum){
    int i;
    int chance;
    int dest;
    for(i = 0; i < FLOOR_CAP; i++){
        if(f->members[i] != NULL){
            chance = random() % 4;
            if(chance == 0){
                dest = random()%FLOORNUM;
                if(dest != fnum){
                    f->members[i]->dest = dest;
                    if(dest > fnum){
                        queue_enque(f->up, f->members[i]);
                    }
                    else{
                        queue_enque(f->down, f->members[i]);
                    }
                    f->members[i] = NULL;
                    f->memnum--;
                }
            }
        }
    }

}

void update_floor(floor* f, Queue* q){
    Person* p = 0;
    while(p = queue_deque(q)){
        floor_enter(f, p);
    }
}

void showstate(floor* level, elevator* el){
    int i;
    for(i = 0; i< FLOORNUM; i++){

    }


}
