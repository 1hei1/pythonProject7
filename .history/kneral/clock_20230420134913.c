#include </home/heige/source/include/clock.h>
#include </home/heige/source/include/io.h>

void set_clock_control(u8 setting){
    outb(clock_control,setting);

}
void set_clock_startnmb(u8 clock_nmb,u16 start_number){
    outb(clock_nmb,start_number&0xff);
    outb(clock_nmb,(start_number>>8)&0xff);

}
u16 get_clock(u8 clock_nmb,u8 setting){
    u8 mode = (setting>>4)&0b0011;
    u8 number_l,number_h;
    u16 number;
    switch (mode)
    {
    case 0b0000:
        number_l = inb(clock_nmb);
        number_h = inb(clock_nmb);
        number = (number_h<<8)+number_l;
        return number;
        break;
    case 0b0001:

        number_l = inb(clock_nmb);
        return number_l;
        break;
    case 0b0010:
        number_h = inb(clock_nmb);
        return number_h;
        break;
    case 0b0011:
        outb(clock_control,setting&0b11000000);
        number_l = inb(clock_nmb);
        outb(clock_control,setting&0b11000000);
        number_h = inb(clock_nmb);
        number = (number_h<<8)+number_l;
        return number;
        break;
    
    default:
        break;
    }
}
