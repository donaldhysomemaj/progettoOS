#include "scheduler.h"


Queue system_proc_queue;
Queue interactive_proc_queue;
Queue user_proc_queue;

CPU *cpu;


void scheduler_init(){
    init_CPU(CPU_CORE_NUM);
    cpu = get_virtual_cpu();

    system_proc_queue = new_queue();
    interactive_proc_queue = new_queue();
    user_proc_queue = new_queue();
}

void run_process(PROCESS *p){
    Item i = new_item(p);
    push(system_proc_queue, i);
}


void start_scheduling(){
    int i = 0;

    while(1){
        Item item = pop(system_proc_queue);
       
        if(item == NULL){
            printf("TERMINATED");
            return;
        }
        
        printf("aaaaa\n");


        CORE *core = get_cpu_core(cpu, i++);
        PROCESS *p = get_info(item);
        execute_process(p, core);
    }   


}