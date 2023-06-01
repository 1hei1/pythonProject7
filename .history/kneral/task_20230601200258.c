#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>

struct task_table_pointers {
    char ID;
    int address;
} __attribute__((__packed__));

struct task_table_pointers  task_tables[25];//任务列表



task_tables[0].ID = 0;


