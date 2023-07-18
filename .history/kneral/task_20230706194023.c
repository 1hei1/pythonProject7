#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>
#include </home/heige/source/include/printx.h>
//任务池
struct tasks_pool tasks;
struct task_node task_ready_header;
struct task_node task_ready_ender;
struct task_node task_run_header;
struct task_node task_run_ender;


void schedule(){
    //print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    struct task_t *next_task;
    struct task_t *cur_task;
    next_task = task_ready_header.next_task;
    cur_task = task_run_header.next_task;
    if(next_task->text == cur_task->text)
    {
        next_task = next_task->next_task;
    }
    if(next_task == &task_ready_ender){
        next_task = task_ready_header.next_task;
    }
    cur_task->status = READY;
    next_task->status = RUNNING;
    int sp = next_task->stack;

    //将下个任务加入执行队列

    // print("okok");
    // if(next_task->stack->eip  == 0){
    //     next_task->stack->eip = next_task->text;
    //     next_task->stack->cs = 0x08;
    //     //next_task->stack->ss = 0x08;
    //     next_task->stack->esp = next_task->stack;
    // }
    
    tasks_order();
    int sp = tasks.tasks_pcb[2]->stack;
    asm volatile("movl %0,%%eax \n\t"
    ::"r"(sp)//如果有输出输出编号考前，输入靠后“r”表示先将变量保存在任意一个通用寄存器里
    );
    
};


void init_task_point(){
    task_ready_ender.fond_task = &task_ready_header;
    task_ready_header.next_task = &task_ready_ender;
    task_run_ender.fond_task = &task_run_header;
    task_run_header.next_task = &task_run_ender;
    
}
//生成任务队列
char tasks_order()
{
    struct task_t* task_node;

    for(int i=0;i<max_task;i++)
    {
        switch(tasks.tasks_pcb[i]->status)
        {
            case READY:
                if(tasks.tasks_pcb[i]->in_order==1)
                {
                    break;
                }
                else if(task_ready_ender.fond_task == &task_ready_header)
                {
                    task_ready_header.next_task = tasks.tasks_pcb[i];
                    task_ready_ender.fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->fond_task = &task_ready_header;
                    tasks.tasks_pcb[i]->next_task = &task_ready_ender;
                    tasks.tasks_pcb[i]->in_order=1;
                    break;
                }
                else 
                {
                    task_node = task_ready_ender.fond_task;
                    task_node->next_task = tasks.tasks_pcb[i];

                    task_ready_ender.fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->fond_task = task_node;
                    tasks.tasks_pcb[i]->next_task = &task_ready_ender;
                    tasks.tasks_pcb[i]->in_order=1;
                    break;
                }

            case RUNNING:
                // if(tasks.tasks_pcb[i]->in_order==1)
                // {
                //     task_ready_header.next_task = tasks.tasks_pcb[i]->next_task;
                //     tasks.tasks_pcb[i]->in_order = 0;
                // }
                task_run_header.next_task = tasks.tasks_pcb[i];
                task_run_ender.fond_task = tasks.tasks_pcb[i];

                break;

            

            //
            //
            //  省略········
            //
            //
                
                

        }
    }
    return 1;
};


char init_pcb(char ID,struct task_t* task_pcb,char *name,int* task_space)
{
    struct task_t*pcb;
    pcb = task_pcb;
    
    pcb->stack = (int)task_pcb+page_size-68;
    pcb->status = READY;
    pcb->priority = 3;
    pcb->ticks = 10;
    pcb->jiffies =100;
    for(int i=0;i<TASK_NAME_LEN;i++){
        pcb->name[i] = name[i];
    };
    pcb->text = task_space;
    pcb->in_order = 0;
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





char creat_task(char *name,int* code){

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
    struct task_t *task = task_pcb;
    
    task->stack->eip = task->text;
    task->stack->cs = 0x08;
    task->stack->eflage = 0b000000000000000000000001000000000;
        //next_task->stack->ss = 0x08;
    task->stack->esp = task->stack;
    memory_copy(code,task_space,1024);
    tasks_order();

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


char change_task(int ID,int state){
    tasks.tasks_pcb[ID]->status = state;
    tasks_order();

}





