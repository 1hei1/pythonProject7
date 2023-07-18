#include </home/heige/source/include/beep.h>
#include </home/heige/source/include/clock.h>
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/io.h>
#include </home/heige/source/include/printx.h>

void start_beep(void){
    int i=100000;
    u8 setting= 0b10110110;
    set_clock_control(setting);
    set_clock_startnmb(clock_3,beep);
    outb(beep_port,0b00000011);
    while(i--);
    for(;i<500;i++){
        outb(beep_port,0b00000000);
    };

    print("beep");
    

}