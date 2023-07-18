#include </home/heige/source/include/delay.h>
#include </home/heige/source/include/task.h>



void delay(int ms)
{
    task_t * task = running_task();
    task_block(task,ms,SLEEP);
}