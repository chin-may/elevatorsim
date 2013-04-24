#include <stdlib.h>
#include "queue.h"
#include "Person.h"

Queue::Queue(){
    head = NULL;
    tail = NULL;
    length = 0;
}

Node::Node( Person* data_p, Node* next_p){
    data = data_p;
    next = next_p;
}

void Queue::enque(Person* data){
    if(head == NULL){
        head = new Node(data,NULL);
        tail = head;
    }
    else{
        Node* ins = new Node(data, NULL);
        tail->next = ins;
        tail = ins;
    }
    length++;
}

Person* Queue::deque(){
    if(head == NULL){
        return NULL;
    }
    else{
        Node* ret = head;
        head = head->next;
        length--;
        return ret->data;
    }
}

