#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
struct task_table_pointers task_tables[256];//任务列表

task_tables[0] =0;
task_tables[0] = &task2;


