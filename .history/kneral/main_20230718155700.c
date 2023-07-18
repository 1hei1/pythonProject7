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
#include </home/heige/source/include/delay.h>

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
    print("CCCCm");
    while (1)
    {
        // print("cccm");
        // asm volatile("int $0x28");
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
    task_t *t = 0;
    t = running_task();

    print("hahaha");
    // print("uu");
    while (1)
    {
        print("787");
        delay(240);
        print("uuiduu");
    }
}

void _ofp task0()
{

    task_t *taskoo;
    print("6666");
    // interrupt_disalow();
    // taskoo = running_task();
    // interrupt_allow();

    // print("okkkkkkkkkkk");

    while (1)
    {
        // get_date();
        // m = get_s();

        // print("666");
        // print("test ok");

        // if (n < m)
        // {
        //     n = m;
        //     print(" \n NOW DATA IS %d \n", n);
        //     start_beep();
        //     //get_date();
        //     if (n >= 59)
        //     {
        //         n = 0;
        //     }
        // }
        // delay(5);
        // print("test time");
        // get_date();

        // asm volatile("int $0x28");
    }
}

void init_kneral()
{

    init_gdt();
    init_interrupt();
    interrupt_disalow();
    init_page();
    init_pageuse_table();

    get_date();
    // start_beep();
    init_pic();

    init_task_point();
    char ID1 = creat_task("task1", &taskn, 10, 300);
    char ID2 = creat_task("task2", &taskm, 12, 300);
    char ID3 = creat_task("task2", &taskpp, 5, 300);
    char ID4 = creat_task("task2", &taskb, 12, 800);
    char ID6 = creat_task("task3", &task0, 8, 300);
    char ID5 = creat_task("task2", &taskq, 9, 700);

    set_clock_interrupt(ms_250, on);
    interrupt_allow();
    while (1);
}
