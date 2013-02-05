#include <stdio.h>
#include "queue.h"
#include "Person.h"

int main(){
    Person* p = person_new(1);
    Queue* que = queue_new();
    queue_enque(que, p);
    queue_enque(que, person_new(66));
    printf("enqued\n");
    p = queue_deque(que);
    printf("one: %d\n", p->id);
    p = queue_deque(que);
    printf("two: %d\n", p->id);
    return 0;
}
