#include <stdlib.h>

#include "process.h"

int cur_pid = 0;


PROCESS *create_new_process(void* (*task)(void*), void *param, int priority){
    PROCESS *p = (PROCESS*) malloc(sizeof(PROCESS)); 
    p->pid = cur_pid++;
    p->task = task;
    p->param = param;
    p->priority = priority;
    return p;
}
