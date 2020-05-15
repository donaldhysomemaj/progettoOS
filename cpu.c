#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "cpu.h"
#include <pthread.h> 


CPU virtual_cpu;
int max_core_number;



CPU *get_virtual_cpu() {    
    return &virtual_cpu;
}

void init_CPU(int core_number){
    virtual_cpu.core = malloc(sizeof(CORE)*core_number);
    for(int i=0; i<core_number; i++){
        virtual_cpu.core[i].status = FREE;
        virtual_cpu.core[i].core_num = i;
    }
    max_core_number = core_number;
}

CORE *get_cpu_core(CPU *cpu, int num){
    if(num >= max_core_number){
        printf("Max core number exception\n");
        exit(1);
    }
    return &cpu->core[num];
}


typedef struct CONTEXT{
    CORE *core;
    PROCESS *proc;
}CONTEXT;


void *task_runner(void *context){
    CONTEXT *cx = (CONTEXT*)context;

    //EXECUTE TASK IN A NEW THREAD
    pthread_t thread;
    printf("Core %d executing...\n", cx->core->core_num);
    pthread_create(&thread, NULL, cx->proc->task, (void * restrict)cx->proc->param);
    
    //WAIT FOR TASK TO END
    pthread_join(thread, NULL);

    //SET CORE STATUS TO FREE
    cx->core->status = FREE;
    printf("Core %d terminated execution\n", cx->core->core_num);
    free(context);
    return NULL;
}

void execute_process(PROCESS *proc, CORE *core){
    if(core->status == BUSY){
        printf("CORE busy\n");
        exit(1);
    }

    core->status = FREE;

    CONTEXT *cx = malloc(sizeof(CONTEXT));
    cx->core = core;
    cx->proc = proc;

    pthread_t thread1;
    pthread_create(&thread1, NULL, task_runner, (void * restrict)cx);
}


