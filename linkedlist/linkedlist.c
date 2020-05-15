#include "linkedlist.h"

void LinkedList_init_(LinkedList *list){
    list->head = 0;
    list->tail = 0;
    list->size = 0;
}

void LinkedList_insert(LinkedList *list, LinkedListNode *previous, LinkedListNode *node){
    #ifdef _LIST_DEBUG_
        //We assume that the node isn't already into the list
        LinkedListNode *instance = LinkedList_find(list, node);
        assert(!instance && "Node already into the list");

        if(previous){
            LinkedListNode *instance = LinkedList_find(list, previous);
            assert(instance && "Previous node not into the list");
        }
    #endif

    if(previous == 0){
        list->head = node;
        list->tail = node;
    }
    else{
        LinkedListNode *next = previous->next;
        node->next = next;
        node->prev = previous;
        previous->next = node;

        if(next){
            next->prev = node; 
        }
        else{
            list->tail = node;
        }
    }
    list->size++;
}

LinkedListNode* LinkedList_find(LinkedList *list, LinkedListNode *node){
    LinkedListNode *head = list->head;
    while(head){
        if(head == node)
            return node;
        head = head->next;
    }
    return 0;
}

LinkedListNode* LinkedList_remove(LinkedList *list, LinkedListNode *node){
    #ifdef _LIST_DEBUG_
        //We assume that the node is into the list
        LinkedListNode *instance = LinkedList_find(list, node);
        assert(instance && "Removing node not into the list");
    #endif

    if(list->size == 0)
        return 0;

    LinkedListNode *prev = node->prev;
    LinkedListNode *next = node->next;

    if(next)
        next->prev=prev;
    if(prev)
        prev->next=next;
    if(node==list->head)
        list->head=next;
    if(node==list->tail)
        list->tail=prev;
    
    list->size--;
    node->next = node->prev = 0;
    return node;
}


LinkedListNode* LinkedList_remove_first(LinkedList *list){    
    #ifdef _LIST_DEBUG_
        assert(list->head && "Removing from void list error");
    #endif
    
    if(!list->head)
        return 0;

    return LinkedList_remove(list, list->head);
}

LinkedListNode* LinkedList_remove_last(LinkedList *list){
    #ifdef _LIST_DEBUG_
        assert(list->tail && "Removing from void list error");
    #endif

    if(!list->head)
        return 0;

    return LinkedList_remove(list, list->tail);
}