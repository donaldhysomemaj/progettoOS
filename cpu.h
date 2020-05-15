#pragma once
#include "process.h"


typedef enum {BUSY, FREE} CORESTATUS;


typedef struct CORE{
    CORESTATUS status;
    int core_num; 
}CORE;


typedef struct CPU{
    CORE *core;
}CPU;




void init_CPU(int core_number);

CPU *get_virtual_cpu();

CORE *get_cpu_core(CPU *cpu, int num);

void execute_process(PROCESS *proc, CORE *core);
