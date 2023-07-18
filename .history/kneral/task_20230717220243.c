#include </home/heige/source/include/task.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/math.h>
#include </home/heige/source/include/memory.h>
#include </home/heige/source/include/printx.h>

// 任务池
struct tasks_pool tasks;
struct task_node task_ready_header;
struct task_node task_ready_ender;
struct task_node task_run_header;
struct task_node task_run_ender;
struct task_node task_sleep_header;
struct task_node task_sleep_ender;

int global_ticks = 0;
void schedule()
{
    struct task_t *next_task,*cur_task;

    
    
    check_timer();
    global_ticks++;

    next_task = search_task();
    // next_task->status=RUNNING;




    int sp = next_task->stack;
    if (next_task->magic != stack_magic)
    {
        
        asm volatile("int $0x1");
        print("hahah erro");
        while (1);
    }
    asm volatile("movl %0,%%eax \n\t" ::"r"(sp) // 如果有输出输出编号考前，输入靠后“r”表示先将变量保存在任意一个通用寄存器里
    );
}

void check_timer()
{
    //struct task_t *task,*unlock_task;
    //struct task_node * task;
    
    task_t *taskppp = task_run_header.next_task;
    while (1)
    {
        print("ppp");
    }
    
    // while((task!=&task_sleep_ender)&&(task->next_task!=end))
    // {

        
    //     if(global_ticks==task->sleep_ticks)
    //     {
    //         unlock_task = task;
    //         task = task->next_task;
    //         task_unblock(unlock_task,READY);
    //         continue;
            
    //     }
    //     task = task->next_task;
    // }
}

void init_task_point()
{
    task_ready_ender.fond_task = &task_ready_header;
    task_ready_ender.next_task = end;
    task_ready_header.next_task = &task_ready_ender;
    task_ready_header.fond_task = font;
    task_run_ender.fond_task = &task_run_header;
    task_run_ender.next_task = end;
    task_run_header.next_task = &task_run_ender;
    task_run_header.fond_task = font;
    task_sleep_ender.fond_task = &task_sleep_header;
    task_sleep_ender.next_task = end;
    task_sleep_header.next_task = &task_sleep_ender;
    task_sleep_header.fond_task = font;
}
// 生成任务队列
char tasks_order(int select, ...)
{

    switch (select)
    {
    case update_auto:
        init_task_point();
        for (int i = 0; i < max_task; i++)
        {

            switch (tasks.tasks_pcb[i]->status)
            {

            case READY:
                // if (tasks.tasks_pcb[i]->in_order == 1)
                // {
                //     break;
                // }
                if (task_ready_header.next_task != &task_ready_ender)
                {
                    task_t *task;
                    task = task_ready_header.next_task;
                    task_ready_header.next_task = tasks.tasks_pcb[i];
                    task->fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->next_task = task;
                    tasks.tasks_pcb[i]->fond_task = &task_ready_header;
                    //tasks.tasks_pcb[i]->in_order = 1;
                }

                else
                {

                    struct task_node *task;
                    task = task_ready_header.next_task;
                    task_ready_header.next_task = tasks.tasks_pcb[i];
                    task->fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->next_task = task;
                    tasks.tasks_pcb[i]->fond_task = &task_ready_header;
                    //tasks.tasks_pcb[i]->in_order = 1;
                }
                break;
            case RUNNING:
                if (task_run_header.next_task == &task_run_ender)
                {
                    asm volatile("int $0x0");
                }

                else
                {

                    task_run_header.next_task = tasks.tasks_pcb[i];
                    task_run_ender.fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->fond_task = &task_run_header;
                    tasks.tasks_pcb[i]->next_task = &task_run_ender;
                    //tasks.tasks_pcb[i]->in_order = 0;
                }
                break;
            case SLEEP:
                if(task_sleep_header.next_task == &task_sleep_ender)
                {
                    task_sleep_header.next_task = tasks.tasks_pcb[i];
                    task_sleep_ender.fond_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->fond_task = &task_sleep_header;
                    tasks.tasks_pcb[i]->next_task = &task_sleep_ender;

                }
                else
                {
                    tasks.tasks_pcb[i]->next_task = task_sleep_header.next_task;
                    task_sleep_header.fond_task = tasks.tasks_pcb[i];
                    task_sleep_header.next_task = tasks.tasks_pcb[i];
                    tasks.tasks_pcb[i]->fond_task = &task_sleep_header;
                    
                }
                break;
            }
        }
        break;
    case update_change:
        break;
    }
};

task_t * running_task()
{
    asm volatile("movl %esp,%eax \n\t"
                 "andl $0xfffff000,%eax \n");
}


//任务阻塞
void task_block(task_t *task_now, int sleep_ticks, int status)
{
    //task_t *task = running_task();
    switch (status)
    {
    case SLEEP:
        task_now->status = SLEEP;
        task_now->sleep_ticks = sleep_ticks+global_ticks;
        tasks_order(update_auto);
        // if (task == )
        // {
        //     task_change();
        // }
        task_change();
        break;

    default:
        break;
    }
}

//任务解锁
void task_unblock(task_t * task,int status)
{
    print("uu");
    task->status = status;
    task->sleep_ticks = 0;
    tasks_order(update_auto);
}

char init_pcb(char ID, struct task_t *task_pcb, char *name, int *task_space, int priority, int ticks)
{
    struct task_t *pcb;
    pcb = task_pcb;

    pcb->stack = (int)task_pcb + page_size - 68;
    pcb->status = READY;
    pcb->priority = priority;
    pcb->ticks = 10;
    pcb->jiffies = 100;
    for (int i = 0; i < TASK_NAME_LEN; i++)
    {
        pcb->name[i] = name[i];
    };
    pcb->text = task_space;
    pcb->in_order = 0;
    pcb->uid = ID;
    pcb->gid = ID;
    pcb->pde = 0x1000;
    pcb->umask = 0;
    pcb->flags = 2023;
    pcb->magic = stack_magic;
}

int get_free_task()
{
    for (int i = 1; i <= max_task; i++)
    {
        if (tasks.tasks_pcb[i] == 0)
        {
            return i; // 第i个任务为空闲位
        }
    }
}

struct task_t *search_task()
{
    int max;
    struct task_t *task, *mid;

    // 任务头
    task = task_ready_header.next_task;
    mid = task->next_task;
    max = task->ticks;
    // return task->next_task;

    // 寻找最高特权级任务
    while (mid != &task_ready_ender && mid != end)
    {

        if (mid->ticks == task->ticks)
        {
            if (mid->priority > task->priority)
            {
                task = mid;
                max = task->ticks;
            }
        }

        else if (mid->ticks > task->ticks)
        {
            task = mid;
            max = task->ticks;
        }
        mid = mid->next_task;
    }
    task->ticks--;
    if (task->ticks == 0)
    {
        task = task_ready_header.next_task;
        while (mid != &task_ready_ender && mid != end)
        {
            task->ticks = task->priority;
            task = task->next_task;
        }
    }
    return task;
}

char creat_task(char *name, int *code, int priority, int ticks)
{

    // 先实现内核级线程

    int *last_task;
    // 首先申请一页内存作为pcb
    int *task_pcb = allow_page(1);

    // 再申请一页存放代码
    int *task_space = allow_page(1);

    // 任务总数加1
    tasks.total_tasks++;

    // 获取空任务
    int last_task_id = get_free_task();
    last_task = &tasks.tasks_pcb[last_task_id];

    // 将新任务节点送入任务池
    *last_task = task_pcb;

    // 初始化pcb
    init_pcb(last_task_id, task_pcb, name, task_space, priority, ticks);
    struct task_t *task = task_pcb;

    task->stack->eip = task->text;
    task->stack->cs = 0x08;
    task->stack->eflage = 0b000000000000000000000001000000000;
    task->stack->esp = task->stack;
    task->stack->ds = 0x10;
    task->stack->es = 0x10;
    task->stack->gs = 0x10;

    // 将进程代码移入
    memory_copy(code, task_space, 1024);
    tasks_order(update_auto);

    return last_task_id; // 任务的id
}

char delete_task(char ID)
{
    struct task_node *delete_task = &tasks.tasks_pcb[ID];

    // 释放任务内存
    free_page(1, delete_task->task_pcb->text);
    free_page(1, (int)delete_task->task_pcb);

    // 清空任务
    tasks.tasks_pcb[ID] = 0;

    // 任务总数 -1
    tasks.total_tasks--;
}

char change_task(int ID, int state)
{
    tasks.tasks_pcb[ID]->status = state;
    tasks_order(update_auto);
}
