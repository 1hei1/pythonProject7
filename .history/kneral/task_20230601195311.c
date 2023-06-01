#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
struct task_table_pointers task_table_pointer[256];//任务列表

task_table_pointer[0].ID=1;
task_table_pointer[0].address = &task2;


