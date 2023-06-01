#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>

struct tasks_manger task_list;

//int task_tables = (int*)&task2;

char task_tables(struct tasks_manger * tasks){
    if(tasks->total_tasks == 0){
        return -1;
    }
    char max_privilege = tasks->tasks[0].privilege;
    char max_ID = tasks->tasks[0].ID;
    int max_address = tasks->tasks[0].address;
    for (int i=0;i<=tasks->total_tasks;i++){

        if(tasks->tasks[i+1].privilege>max_privilege){
            max_privilege = tasks->tasks[i+1].privilege;
            max_ID = tasks->tasks[i+1].ID;
            max_address = tasks->tasks[i+1].address;
        }

    }

    void (* task_now)();
    task_now = (void (*)(void))max_address;
    task_now();
    return 1;

    
}





