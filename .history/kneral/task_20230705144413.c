#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>

//任务池
struct tasks_pool tasks;


int task_tables(){

    
}



char init_pcb(char ID,struct task_node*task,char *name,int* task_space)
{
    struct task_t*pcb;
    pcb = task->task_pcb;
    pcb->stack = task->task_pcb+page_size;
    pcb->status.status = READY;
    pcb->priority = 3;
    pcb->ticks = 10;
    pcb->jiffies =100;
    for(int i=0;i<TASK_NAME_LEN;i++){
        pcb->name[i] = name[i];
    };
    pcb->text = task_space;
    pcb->uid = ID;
    pcb->gid = ID;
    pcb->pde = 0x1000;
    pcb->umask = 0;
    pcb->flags = 2023;
    pcb->magic = 1024;
}

int get_free_task(){
    for(int i=1;i<=tasks.total_tasks;i++){
        if(tasks.tasks[i]->task_pcb==0){
            return i;//第i个任务为空闲位
        }
    }
}




//创建任务--根据当前的任务总数确定新创建任务的ID（即：根据当前任务总数+1=当前任务ID），同时任务总数+1
char creat_task(char *name){

//先实现内核级线程

    int * last_task;
    //首先申请一页内存作为pcb
    int* task_pcb = allow_page(1);

    //再申请一页存放代码

    int* task_space = allow_page(1);

    //生成任务标识

    tasks.total_tasks++;

    //生成任务节点

    struct task_node * task_node;
    task_node->next_task=0;
    task_node->task_pcb = task_pcb;
    

   

    //获取空任务
    int last_task_id = get_free_task();
    last_task = &tasks.tasks[last_task_id];

    //将新任务节点送入任务池
    *last_task = &task_node;


    //初始化pcb

    init_pcb(last_task_id,task_node,name,task_space);

    return last_task_id;  //任务的id
    
}



//删除任务---根据给定的ID找到对应的索引，将任务对应的索引的ID置0并判断任务后是否有任务（即：ID！=0）如果有
//将该索引后方的任务全部迁移一个位置，同时任务总数-1；
char delete_task(char ID){
    struct task_node *delete_task = tasks.tasks[ID];

    free_page(1,delete_task->task_pcb->text);
    free_page(1,(int)delete_task->task_pcb);
    
    tasks.tasks[ID] = 0;
    tasks.total_tasks--;


}






