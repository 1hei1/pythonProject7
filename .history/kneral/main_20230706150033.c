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


void init_kneral(){
    
    

    init_gdt();
    init_interrupt();
    interrupt_disalow();
    init_page();
    init_pageuse_table();

    // int start_page = allow_page(10);
    // free_page(10,start_page);
    // start_page = allow_page(6);
    // free_page(6,start_page);


    u8 setting = 0b10100000;
 
    set_clock_control(setting);
    set_clock_startnmb(clock_3,0);

    int i = 0;
    get_date();

    init_task_point();
    char ID = creat_task("task1",&task1);
    char ID2 = creat_task("task2",&task2);

    char ID3 = creat_task("task3",&task3);
    set_clock_interrupt(6,1);
    interrupt_allow();

    while (1)
    {
        /* code */
    }
    





    // delete_task(ID_2);
    // delete_task(ID_1);
    // for(int i=0;i<12;i++){
    // char now = random(1,19);
    // print(now);}


}

