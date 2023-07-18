#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>

//任务池
struct tasks_pool tasks;
struct task_node task_ready_header;

int task_tables(){

    
}




char init_pcb(char ID,struct task_t*task_pcb,char *name,int* task_space)
{
    struct task_t*pcb;
    pcb = task_pcb;
    pcb->stack = task_pcb+page_size;
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
        if(tasks.tasks_pcb[i]==0){
            return i;//第i个任务为空闲位
        }
    }
}





char creat_task(char *name){

//先实现内核级线程

    int * last_task;
    //首先申请一页内存作为pcb
    int* task_pcb = allow_page(1);

    //再申请一页存放代码
    int* task_space = allow_page(1);

    //任务总数加1
    tasks.total_tasks++;


    //获取空任务
    int last_task_id = get_free_task();
    last_task = &tasks.tasks_pcb[last_task_id];

    //将新任务节点送入任务池
    *last_task = task_pcb;


    //初始化pcb
    init_pcb(last_task_id,task_pcb,name,task_space);

    return last_task_id;  //任务的id
    
}




char delete_task(char ID){
    struct task_node *delete_task = &tasks.tasks_pcb[ID];


    //释放任务内存
    free_page(1,delete_task->task_pcb->text);
    free_page(1,(int)delete_task->task_pcb);
    
    //清空任务
    tasks.tasks_pcb[ID] = 0;


    //任务总数 -1
    tasks.total_tasks--;


}






