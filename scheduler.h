#pragma once

#include "linkedlist/queue.h"
#include "process.h"
#include "cpu.h"


#define CPU_CORE_NUM 4


void scheduler_init();
void run_process(PROCESS *p);

void start_scheduling();