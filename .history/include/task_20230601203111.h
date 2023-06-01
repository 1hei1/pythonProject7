#ifndef TASK_H
#define TASK_H


struct tasks {
    char ID;
    int address;
    char privilege;
};

struct tasks_manger {
    char total_tasks;
    struct tasks tasks[256];
};

struct task_status_pointers{
    char ID; //任务ID
    char clocked; //任务是否上锁
    char waiting; //任务是否等待
    char running; //任务是否运行
    int read_able_ower; //任务是否可读--如果不可读，那么ower代表占用者ID
    int write_able_ower;//任务是否科协--如果不可写，那么ower代表占用者ID
};//任务状态


//此函数实现任务的切换

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

// char creat_task(); //创建任务--返回任务ID

// char delete_task(); //删除任务--返回删除是否成功

// char change_task();  //改变任务属性--改变任务的层级关系，任务地址等

// char task_find();   //寻找任务--返回下一次执行的任务ID

// char task_clock();   //任务上锁/解锁

// char task_wait(); //使任务等待








#endif