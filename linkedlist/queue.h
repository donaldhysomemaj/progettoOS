#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// #define _QUEUE_DEBUG

typedef struct ItemNode* Item;
typedef struct Queue_* Queue;

///Generic Queue. Assign the print function of the item that you will be using
Queue new_queue_generic(void (*print_fn)(void*));

Queue new_queue();


Item new_item(void *info);
void *get_info(Item item);

void push(Queue queue, Item item);
Item pop(Queue queue);
void delete_Queue(Queue queue);


void print(Queue queue);