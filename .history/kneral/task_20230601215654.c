#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>

struct tasks_manger tasks;

//int task_tables = (int*)&task2;

char task_tables(){
    tasks.total_tasks = 1;
    tasks.tasks[0].address = &task1;
    tasks.tasks[0].ID = 1;
    tasks.tasks[0].privilege = 1;
    if(tasks.total_tasks == 0){
        return -1;
    }
    char max_privilege = tasks.tasks[0].privilege;
    char max_ID = tasks.tasks[0].ID;
    int max_address = tasks.tasks[0].address;
    for (int i=0;i<=tasks.total_tasks;i++){

        if(tasks.tasks[i+1].privilege>max_privilege){
            max_privilege = tasks.tasks[i+1].privilege;
            max_ID = tasks.tasks[i+1].ID;
            max_address = tasks.tasks[i+1].address;
        }
    }

    void (* task_now)();
    task_now = (void (*)(void))max_address;
    task_now();
    return 1;

    
}


char creat_task(int address){
    char total = tasks.total_tasks;
    if(total == 256){
        return -1;
    }
    for(int i=0;i<256;i++){
        if(tasks.tasks[i].ID == 0){
            tasks.tasks[i].address = address;
            tasks.tasks[i].privilege = 0;
            tasks.tasks[i].ID = total+1;
            tasks.total_tasks++;
            return tasks.total_tasks;
            break;
        }
    }
    return -1;
    
    
}


char delete_task(char ID){
    for(int i=0;i<256;i++){
        if(tasks.tasks[i].ID==ID){
            tasks.tasks[i].ID = 0;
            return 1;
            break;
        }

    }
    return -1;
}






