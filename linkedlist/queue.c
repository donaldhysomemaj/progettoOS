#include "queue.h"

struct ItemNode{
    LinkedListNode parent;
    void *info;
};
struct Queue_{
    LinkedList parent;
    void (*print_function)(void *);
    LinkedList garbage_collector;
}Queue_;

Item new_item(void *info){
    Item item = malloc(sizeof(struct ItemNode));
    item->info = info;
    item->parent.next = 0;
    item->parent.prev = 0;
    return item;
}

void printItem_String(char *info){
    printf("%s - ", info);
}
Queue new_queue(){
    Queue q = malloc(sizeof(Queue_));
    LinkedList_init_((LinkedList*)q);
    q->print_function = (void(*)(void*))printItem_String;
    LinkedList_init_(&q->garbage_collector);
    return q;
}

Queue new_queue_generic(void (*print_fn)(void*)){
    Queue q = malloc(sizeof(Queue_));
    LinkedList_init_((LinkedList*)q);
    q->print_function = print_fn;
    return q;
}

void *get_info(Item item){
    return item->info;
}



void push(Queue queue, Item item){
    LinkedList_insert((LinkedList*)queue, queue->parent.tail, (LinkedListNode*)item);
}

Item pop(Queue queue){
    #ifdef _QUEUE_DEBUG
        assert(queue->parent.size && "Pop operation for a void queue");
    #endif

    Item item = (Item)LinkedList_remove((LinkedList*)queue, queue->parent.head);
    push(((Queue)&(queue->garbage_collector)), item);
    return item;
}


void delete_Queue(Queue queue){
    #ifdef _QUEUE_DEBUG
        assert(!(queue->parent.size == -1) && "Freeing void queue");
    #endif
    
    Item head = (Item)queue->parent.head;
    while(head){
        Item temp = head;
        head = (Item)head->parent.next;
        free(temp);
    }
    queue->parent.size = -1;

    //Freeing Garbage Collector
    head = (Item)queue->garbage_collector.head;
    while(head){
        Item temp = head;
        head = (Item)head->parent.next;
        free(temp);
    }
    queue->garbage_collector.head=0;
    free(queue);    
}


void print(Queue queue){
    #ifdef _QUEUE_DEBUG
        assert(queue->print_function && "Print Function not assigned to the queue");
    #endif

    Item head = (Item)queue->parent.head;
    while(head){
        queue->print_function(head->info);
        head = (Item)head->parent.next;
    }
    printf("\nSize = %d\n", queue->parent.size);
}