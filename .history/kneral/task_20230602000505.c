#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>

struct tasks_manger tasks;

//int task_tables = (int*)&task2;

char task_tables(){
    char next_task = (last_task_index++)%tasks.total_tasks;
    //char next_task = random(0,256);
    //print(next_task);
    char max_privilege,max_ID,max_address;
    if(tasks.total_tasks == 0){
        return -1;
    }

    if(tasks.tasks[next_task].ID!=0){
    max_privilege = tasks.tasks[next_task].privilege;
    max_ID = tasks.tasks[next_task].ID;
    max_address = tasks.tasks[next_task].address;
    }
    else{
    max_privilege = tasks.tasks[last_task_index].privilege;
    max_ID = tasks.tasks[last_task_index].ID;
    max_address = tasks.tasks[last_task_index].address;
    }



    for (int i=0;i<=tasks.total_tasks;i++){

        if(tasks.tasks[i+1].privilege>max_privilege&&last_task!=tasks.tasks[i+1].privilege){
            max_privilege = tasks.tasks[i+1].privilege;
            max_ID = tasks.tasks[i+1].ID;
            max_address = tasks.tasks[i+1].address;
            last_task_index = i;
            last_task = max_ID;
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
            tasks.tasks[i].privilege = 3;
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
            tasks.total_tasks--;
            return 1;
            break;
        }

    }
    return -1;
}






