#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>
#include </home/heige/source/include/type.h>
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

//创建任务--根据当前的任务总数确定新创建任务的ID（即：根据当前任务总数+1=当前任务ID），同时任务总数+1
char creat_task(char *name){

//先实现内核级线程

    struct task_node * last_task;
    //首先申请一页内存作为pcb
    int* task_pcb = allow_page(1);

    //再申请一页存放代码

    int* task_space = allow_page(1);

    //生成任务标识

    char ID = tasks.total_tasks++;

    //生成任务节点

    struct task_node * task_node;
    task_node->next_task=0;
    task_node->task_pcb = task_pcb;
    

    //将任务入任务池
    last_task = tasks.total_tasks;
    for(int i = 0; i < tasks.total_tasks;i++){
        last_task = last_task->next_task;
        if(last_task==0){
            break;
        }
    }
    last_task->next_task = task_node;
    task_node->fond_task = last_task;

    //初始化pcb

    init_pcb(ID,task_node,name,task_space);

    return ID;  
    
}



//删除任务---根据给定的ID找到对应的索引，将任务对应的索引的ID置0并判断任务后是否有任务（即：ID！=0）如果有
//将该索引后方的任务全部迁移一个位置，同时任务总数-1；
char delete_task(char ID){
    struct task_node *delete_task = tasks.next_task;
    for(int i=0;i<tasks.total_tasks;i++){
        
        if(delete_task->task_pcb->gid == ID){
            break;
        }
        delete_task = delete_task->next_task;

    }
    free_page(1,delete_task->task_pcb->text);
    free_page(1,(int*)delete_task->task_pcb);
    
    delete_task->fond_task=delete_task->next_task;
    tasks.total_tasks--;


}






