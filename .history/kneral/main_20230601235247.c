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
    
    
    // // outb(adder,cursor_l);
    // // outb(data,20);
    // char one_little;
    // char *screen = (char *)0xb8000;
    // for (int i=0;i<sizeof(message);i++){
    //     screen[i*2] = message[i]; 
    // }  

    // //clear_screen(screen,4000);
    // set_mouse(40,5);
    // int delay =10;
   
    

    // set_mouse();
    // //set_mouse(screen,pos%80,pos/80);
    // screen_write('\n');
    // clear_screen();
    // screen_write(127);
    // screen_write('a');
    // screen_write('b');
    // screen_write('c');
    // print("abcd%dfg", 100);
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

    char ID_1 = creat_task(&task1);
    char ID_2 = creat_task(&task2);
    char ID_3 = creat_task(&task3);
    set_clock_interrupt(6,1);
    interrupt_allow();
    // for(int i=0;i<12;i++){
    // char now = random(1,19);
    // print(now);}
    delete_task(ID_2);
    while(1){
        delay(1);
        get_s();
        char now = random(1,19);
        //print("\nnow is%d",now);
        if(now == 1){
            delete_task(ID_2);
        }
    }
    // print("pppppppppppppppppppppppppppppppppp");
}

