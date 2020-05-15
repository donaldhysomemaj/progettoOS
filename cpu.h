#pragma once

typedef struct CORE{
    void (*execute)(void (*function)(void *), void *param);    
}CORE;


typedef struct CPU{
    CORE *core;
}CPU;


void init_CPU(int core_number);

CPU get_virtual_cpu();
