#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h> 

// #include <stdarg.h>

#include "cpu.h"
#include "process.h"
#include "scheduler.h"


void *print1(void *arg){
    int num = 0;
    while(num++ < 3){
        printf("    arg: %ld, num = %d\n",(long)arg, num);
        sleep(1);        
    }
    return NULL;
}


int main(){


    scheduler_init();

    
    PROCESS *p1 = create_new_process(print1, (void*)1, 0);
    PROCESS *p2 = create_new_process(print1, (void*)2, 0);
    PROCESS *p3 = create_new_process(print1, (void*)3, 0);
    PROCESS *p4 = create_new_process(print1, (void*)4, 0);
    // printf("aaaaaaaaaaaaaaaaa\n");
    
    run_process(p1);
    run_process(p2);
    run_process(p3);
    run_process(p4);

    start_scheduling();

    sleep(5);

    // PROCESS *p2 = create_new_process(print1, (void*)5, 0);

    // execute_process(p1, core0);

    // execute_process(p2, core1);

    // sleep(5);



   return 0;

}