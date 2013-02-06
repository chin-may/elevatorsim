#include <stdlib.h>
#include "queue.h"
#include "Person.h"

Queue* queue_new(){
    Queue* res;
    res = malloc(sizeof(Queue));
    res->head = NULL;
    res->tail = NULL;
    res->length = 0;
    return res;
}

Node* node_new( Person* data, Node* next ){
    Node* ret = malloc(sizeof(Node));
    ret->data = data;
    ret->next = next;
    return ret;
}

void queue_enque(Queue* q, Person* data){
    if(q->head == NULL){
        q->head = node_new(data,NULL);
        q->tail = q->head;
    }
    else{
        Node* ins = node_new(data, NULL);
        q->tail->next = ins;
        q->tail = ins;
    }
    q->length++;
}

Person* queue_deque(Queue* q){
    if(q->head == NULL){
        perror("Empty queue");
        return NULL;
    }
    else{
        Node* ret = q->head;
        q->head = q->head->next;
        q->length--;
        return ret->data;
    }
}

