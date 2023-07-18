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

void taskn(){
    // interrupt_disalow();
    // outb(0x70,0x8C);
    // inb(0x71);
    // interrupt_allow();
    //int i=1;

    
print("nommm");
        //schedule();
        while (1)
        {
            //interrupt_allow();
            
        }
        

    
}
void taskm(){
    int i=1000000000000;

    print("llkkgg");
    while(i--){

    }
    //asm volatile("int $0x28");
    print("hahaha"); 
    while (1)
    {
        //interrupt_allow();
          
    }
    

    
}
void taskq(){
    print("www");
    while (1);

    
}

void taskp(){
    print(",,,,");
    while (1);
 
    
   
    
}


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
    char ID = creat_task("task1",&taskm);
    char ID2 = creat_task("task2",&taskn);
    // char ID3 = creat_task("task2",&taskq);
    // char ID4 = creat_task("task2",&taskp);


    //change_task(ID,RUNNING);

    // char ID3 = creat_task("task3",&task3);
    // interrupt_allow();
    // set_clock_interrupt(2,1);
    // interrupt_allow();
    // while(1);
    

    // while (1)
    // {
    //     /* code */
    // }
    





    // delete_task(ID_2);
    // delete_task(ID_1);
    // for(int i=0;i<12;i++){
    // char now = random(1,19);
    // print(now);}


}

