#pragma once

typedef struct PROCESS{
    int pid;
    int priority;
    void* (*task)(void*);
    void *param;
}PROCESS;


PROCESS *create_new_process(void* (*task)(void*), void *param, int priority);