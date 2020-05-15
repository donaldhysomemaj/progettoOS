#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h> 


// #include <stdarg.h>

#include "cpu.h"

#define CORE_NUM 4


void print1(void *s){
    int num = 0;
    while(num++ < 10){
        printf("thread %ld, num = %d\n", (long)s, num);
        sleep(1);        
    }
}


int main(){

    init_CPU(CORE_NUM);

    CPU my_cpu = get_virtual_cpu();
    // sleep(1);

    my_cpu.core[1].execute(print1, (void*)1);





    return 0;
}