#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>

struct tasks_manger tasks;


int task_tables(){
    char next_task = (last_task_index+1)%tasks.total_tasks;//随机生成下一个任务的索引
    char max_privilege,max_ID;
    int max_address;
    if(tasks.total_tasks == 0){
        return task_table_none;//任务队列为空，返回错误
    }

    max_privilege = tasks.tasks[next_task].privilege;
    max_ID = tasks.tasks[next_task].ID;
    max_address = tasks.tasks[next_task].address;

    for (int i=0;i<=tasks.total_tasks;i++){

        if(tasks.tasks[i].privilege>max_privilege&&last_task!=tasks.tasks[i].ID){
            max_privilege = tasks.tasks[i].privilege;
            max_ID = tasks.tasks[i].ID;
            max_address = tasks.tasks[i].address;
            last_task_index = i;
            last_task = max_ID;
        }
        else{
            last_task_index = next_task;
            last_task = max_ID;
        }
    }

    

    void (* task_now)();
    task_now = (void (*)(void))max_address;
    task_now();
    return 1;
    // return max_address;

    
}

//创建任务--根据当前的任务总数确定新创建任务的ID（即：根据当前任务总数+1=当前任务ID），同时任务总数+1
char creat_task(int address){
    char total = tasks.total_tasks;
    if(total == 256){
        return task_table_full;//任务队列已满，返回错误
    }
    for(int i=0;i<256;i++){
        if(tasks.tasks[i].ID == 0){ 
            tasks.tasks[i].address = address;
            tasks.tasks[i].privilege = 3;
            tasks.tasks[i].ID = total+1;
            tasks.total_tasks++;
            // return tasks.total_tasks;
            // break;
        }
    }

    int task_address = allow_page(1);//由于现在暂时没有文件系统所以暂时规定每个任务为1个页
    
    set_memory_page(1,task_address,address);




    
    
}



//删除任务---根据给定的ID找到对应的索引，将任务对应的索引的ID置0并判断任务后是否有任务（即：ID！=0）如果有
//将该索引后方的任务全部迁移一个位置，同时任务总数-1；
char delete_task(char ID){
    for(int i=0;i<256;i++){
        if(tasks.tasks[i].ID==ID){
            tasks.tasks[i].ID = 0;
            tasks.total_tasks--;
            if(tasks.tasks[i+1].ID!=0){
                for(int n=i;n<tasks.total_tasks;n++){
                    tasks.tasks[n] = tasks.tasks[n+1];
                }
            }
            return 1;
            break;
        }

    }
    return task_not_find;//未查找到对应的任务，返回错误
}






