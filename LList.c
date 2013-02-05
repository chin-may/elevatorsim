/*
 * Author: Chinmay Bapat(CS10B059)
 * Linked list data structure (Implementation)
 */

#include "LList.h"
#include <stdio.h>
#include <stdlib.h>


Node* node_new( int data, Node* next )
{
    Node* n;
    n = malloc(sizeof(Node));
    n->data = data;
    n->next = next;
    return n;
}


LList* llist_new()
{
    LList *l;
    l = malloc(sizeof(LList));
    l->head = NULL;
    return l;
}

int llist_size( LList* lst )
{
    int size = 0;
    Node* current;
    current = lst->head;
    while(current != NULL){
        size++;
        current = current->next; }
    return size;
}


void llist_print( LList* lst )
{
    Node* current;
    current = lst->head;
    while(current != NULL ) {
        printf("%d ",current->data);
        current = current->next; }

}



int llist_get( LList* lst, int idx )
{
    int i = 0;
    Node* current;
    current = lst->head;
    while((i < idx) && (current != NULL)) {
        i++;
        current = current->next;  }
    return current->data;
}        



LList* llist_append( LList* lst, int data )
{   
    Node* current;
    current = lst->head;
    if(current != NULL) {
        while(current->next != NULL) {
            current = current->next; }
        current->next = node_new( data, NULL ); }
    else lst->head = node_new( data, NULL );
    return lst;
}


LList* llist_prepend( LList* lst, int data )
{
    Node* n;
    n = node_new( data, lst->head );
    lst->head = n;
    return lst;
}

LList* llist_insert( LList* lst, int idx, int data )
{
    Node* current;
    int i = 0;
    current = lst->head;
    if(idx == 0) {
        lst->head = node_new(data, lst->head); }
    else {
        while( (i<idx-1) && (current != NULL) ) {
            current = current->next;
            i++; }
        current->next = node_new( data, current->next ); }
    return lst;
}


LList* llist_remove_last( LList* lst )
{
    Node* current = lst->head;
    if(current->next == NULL) {
        free(lst->head);
        lst->head = NULL; }
    else {
        while((current->next)->next != NULL)
            current = current->next;
        free(current->next);
        current->next = NULL;
        return lst; }
}


LList* llist_remove_first( LList* lst )
{
    Node* temp = lst->head;
    lst->head = temp->next;
    free(temp);
    return lst;
}


LList* llist_remove( LList* lst, int idx )
{
    Node* current = lst->head;
    Node* temp;
    int i = 0;
    while((current != NULL ) && (i < idx-1)) {
        current = current->next;
        i++; }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return lst;

}        
