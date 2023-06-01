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

char task_tables();

// char creat_task(); //创建任务--返回任务ID

// char delete_task(); //删除任务--返回删除是否成功

// char change_task();  //改变任务属性--改变任务的层级关系，任务地址等

// char task_find();   //寻找任务--返回下一次执行的任务ID

// char task_clock();   //任务上锁/解锁

// char task_wait(); //使任务等待










#endif