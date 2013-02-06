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
        }
        for(i = 0; i < ELEVATORNUM; i++){
            elevator_move(elev[i]);
            if(elevator_atdest(elev[i]) && ! elev[i]->delay_done){
                elevator_pause(random() % (MAX_WAIT - 2) + 2);
                Person* p;
                Queue* q;
                if(elev[i]->moving > 0){

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
        int i;
        while((floor->members[i] != 0) && (i<FLOOR_CAP)){
            i++;
        }
        if(i == FLOOR_CAP) {
            perror("Floor %d full", i);
            exit(1);
        }
        floor->members[i] = p;
    }
}

void showstate(floor* level, elevator* el){
    int i;
    for(i = 0; i< FLOORNUM; i++){

    }


}
