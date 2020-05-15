#include <stdlib.h>
#include <stdarg.h>
#include "cpu.h"

// void exec1(void (*function()), ...){
//     function(param);
// }

void exec1(void (*function)(void *), void *param){
    function(param);
}
void exec2(void (*function)(void *), void *param){
    function(param);
}
void exec3(void (*function)(void *), void *param){
    function(param);
}
void exec4(void (*function)(void *), void *param){
    function(param);
}

CORE core1 = {.execute = exec1};
CORE core2 = {.execute = exec2};
CORE core3 = {.execute = exec3};
CORE core4 = {.execute = exec4};

CPU virtual_cpu;

void init_CPU(int core_number){
    virtual_cpu.core = malloc(sizeof(CORE)*core_number);
    for(int i=0; i<core_number; i++){
        virtual_cpu.core[i].execute = exec1;


    }
}

CPU get_virtual_cpu() {    
    return virtual_cpu;
}

