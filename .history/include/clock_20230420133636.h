#ifndef CLOCK_H
#define clock_h
#include </home/heige/source/include/type.h>
#define clock_1 0x40
#define clock_2 0x41
#define clock_3 0x42
#define clock_control 0x43


void set_clock_control(u8 setting);//设置时钟控制位
void set_clock_startnmb(u8 clock_nmb,u16 start_number);//设置时钟起始值
u16 get_clock(u8 clock_nmb,u8 setting);//获取时钟当前的值


#endif