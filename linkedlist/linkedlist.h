#pragma once
#include<assert.h>


// #define _LIST_DEBUG_


typedef struct LinkedListNode{
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
}LinkedListNode;

typedef struct {
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
}LinkedList;


void LinkedList_init_(LinkedList *list);
void LinkedList_insert(LinkedList *list, LinkedListNode *previous, LinkedListNode *node);
LinkedListNode* LinkedList_remove(LinkedList *list, LinkedListNode *node);
LinkedListNode* LinkedList_find(LinkedList *list, LinkedListNode *node);

LinkedListNode* LinkedList_remove_first(LinkedList *list);
LinkedListNode* LinkedList_remove_last(LinkedList *list);


