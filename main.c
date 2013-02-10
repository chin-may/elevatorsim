#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "Person.h"
#include "floor.h"
#include "consts.h"
#include "elevator.h"

void set_external_tasks(floor* f, elevator* elev[], int fnum);
void showstate(floor* level[], elevator* el[]);
void update_floor(floor* f, Queue* q);
void update_queues(floor* f, int fnum);
int add_new_entrants(floor* gr, int currid);

int main(){
    floor* level[FLOORNUM];
    int i;
    int currid = 0;
    for(i = 0; i < FLOORNUM; i++){
        level[i] = floor_new();
    }
    elevator* elev[ELEVATORNUM];
    for(i = 0; i < ELEVATORNUM; i++){
        elev[i] = elevator_new();
    }
    srand(time(NULL));

    while(1){
        currid = add_new_entrants(level[0], currid);
        set_external_tasks(level[0], elev,0);
        for(i = 1; i < FLOORNUM; i++){
            update_queues(level[i], i);
            set_external_tasks(level[i], elev,i);
        }
        for(i = 0; i < ELEVATORNUM; i++){
            elevator* e = elev[i];
            elevator_move(e);
            floor* currentfloor = level[ e->location ];
            if(e->moving != 0 && elevator_atdest(e)){ 
                elevator_pause(e,random() % (MAX_WAIT - 2) + 2); //Also clears target
                Person* p;
                Queue* q;
                q = elevator_leave(e);
                //At ground floor people just leave building
                if(e->location > 0){
                    update_floor( currentfloor, q );
                }
                //If elevator has further destinations in same direction, only
                //those passengers can enter
                if(elevator_hasfurther(e)){
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
                    elevator_setdest(e);
                }
                //If no further targets, longer q gets preference
                else{
                    if(currentfloor->up->length == 0 && currentfloor->down->length == 0){
                        elevator_setdir_ext(e);
                    }
                    else if(currentfloor->up->length > currentfloor->down->length){
                        while(e->pnum < ELEVATOR_CAP && currentfloor->up->length > 0){
                            p = queue_deque(currentfloor->up);
                            elevator_enter(e, p);
                        }
                        e->moving = 1;
                    }
                    else {
                        while(e->pnum < ELEVATOR_CAP && currentfloor->down->length > 0){
                            p = queue_deque(currentfloor->down);
                            elevator_enter(e, p);
                        }
                        e->moving = -1;
                    }
                    elevator_setdest(e);
                }
            }
            if(e->moving == 0){
                Person* p;
                if(currentfloor->up->length == 0 && currentfloor->down->length == 0){
                    elevator_setdir_ext(e);
                }
                else if(currentfloor->up->length > currentfloor->down->length){
                    while(e->pnum < ELEVATOR_CAP && currentfloor->up->length > 0){
                        p = queue_deque(currentfloor->up);
                        elevator_enter(e, p);
                    }
                    e->moving = 1;
                }
                else {
                    while(e->pnum < ELEVATOR_CAP && currentfloor->down->length > 0){
                        p = queue_deque(currentfloor->down);
                        elevator_enter(e, p);
                    }
                    e->moving = -1;
                }
                elevator_setdest(e);
            }
        }
        showstate(level, elev);
        //getc(stdin);
        sleep(1);
        printf("----------------------------------------------------------------------\n");
    }
    return 0;
}


int add_new_entrants(floor* gr, int currid){
    int num = rand()%(MAX_ENT + 1);
    int i;
    Person* p;
    for(i = 0; i < num; i++){
        p = person_new(++currid);
        p->dest = random()%(FLOORNUM - 1) + 1;
        queue_enque(gr->up, p);
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
    int success;
    while(p = queue_deque(q)){
        success = floor_enter(f, p);
        if(!success){
            p->dest = 0;
            queue_enque(f->down, p);
        }
    }
}

void showstate(floor* level[], elevator* el[]){
    int i;
    for(i = 0; i< FLOORNUM; i++){
        printf("Floor %d\n",i);
        floor_print(level[i]);
    }
    for(i = 0; i < ELEVATORNUM; i++){
        printf("\nElevator %d\n",i);
        elevator_print(el[i]);
    }
}

void set_external_tasks(floor* f, elevator* elev[], int fnum){
    if(f->up->length > 0 || f->down->length > 0){
        int already_set = 0;
        int has_elev = 0;
        int i;
        for(i = 0; i < ELEVATORNUM; i++){
            if(elevator_hasdest(elev[i],fnum) ){
                already_set = 1;
            }
            if(elev[i]->location == fnum){
                has_elev = 1;
            }
        }
        if(!already_set && !has_elev){
            int choice = random() % ELEVATORNUM;
            elev[choice]->ext_dest[fnum] = 1;
        }
    }
}
