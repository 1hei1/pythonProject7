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
    //set_clock_interrupt(3,1);
    //interrupt_allow();

    // print("pppppppppppppppppppppppppppppppppp");
}

