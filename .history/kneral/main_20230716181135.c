#include </home/heige/source/include/main.h>
#include </home/heige/source/include/io.h>
#include </home/heige/source/include/screen.h>
#include </home/heige/source/include/printx.h>
#include </home/heige/source/include/string.h>
#include </home/heige/source/include/global.h>
#include </home/heige/source/include/interrupt.h>
#include </home/heige/source/include/handle.h>
#include </home/heige/source/include/clock.h>
#include </home/heige/source/include/beep.h>
#include </home/heige/source/include/time.h>
#include </home/heige/source/include/memory.h>
#include </home/heige/source/include/task.h>
#include </home/heige/source/include/math.h>

void _ofp taskn()
{

    int i = 1;

    print("AAAA");
    while (1)
    {
    }
}
void _ofp taskm()
{

    print("BBBB");
    while (1)
    {
    }

    while (1)
    {
    }
}
// 这里要省略栈帧
void _ofp taskq()
{
    print("CCCC");
    while (1)
    {
    }
}

void _ofp taskpp()
{
    print("DDDD");
    while (1)
    {
    }
}

void _ofp taskb()
{
    print("9999");
    while (1)
    {
    }
}

void _ofp task0()
{

    print("6666");
    //task_t * task = running_task();
    int i = 1000000000;
    int n, m;

    while (1)
    {
       // get_date();
        m = get_s();
        
        //task_block(task,10,SLEEP);

        if (n < m)
        {
            n = m;
            print(" \n NOW DATA IS %d \n", n);
            start_beep();
            //get_date();
            if (n >= 59)
            {
                n = 0;
            }
        }
        // delay(5);
        // print("test time");
        //get_date();
    }
}

void init_kneral()
{

    
    init_gdt();
    init_interrupt();
    interrupt_disalow();
    init_page();
    init_pageuse_table();

    // u8 setting = 0b10100000;

    // set_clock_control(setting);
    // set_clock_startnmb(clock_3, 0);


    int i = 0;
    get_date();
    start_beep();
    init_pic();

    init_task_point();
    // char ID = creat_task("task1",&taskn,10,300);
    // char ID2 = creat_task("task2",&taskm,12,300);
    // char ID3 = creat_task("task2",&taskpp,5,300);
    // char ID4 = creat_task("task2",&taskq,8,300);
    // char ID5 = creat_task("task2",&taskb,6,300);
    char ID6 = creat_task("task2", &task0, 6, 300);

    // change_task(ID,RUNNING);

    // char ID3 = creat_task("task3",&task3);
    // interrupt_allow();
    set_clock_interrupt(μs_976, on);
    interrupt_allow();
    while (1);


}
